#include <zmq.hpp>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <getopt.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <pillowtalk.h>
#include "m2pp.hpp"
#include "concept_resolver.h"


typedef vector<char*> SnippetList;

/* Globals */

static ConceptResolver* __cr = NULL;

/* Static methods */
static std::string conceptualize(m2pp::request& res);
static void split_into_vector(SnippetList& vec, char* input);

/* Pull off Image's from the download queue to download them and put them on the resize queue*/
static void* download(std::string sender_id, std::string pub_address, std::string sub_address) {
  signal(SIGPIPE,SIG_IGN);
	m2pp::connection conn(sender_id, pub_address,sub_address);
  for(;;) {
    m2pp::request req = conn.recv();

    std::string json = conceptualize(req);
    conn.reply_http(req,json);
  }
  return 0;
}

int main(int argc,char** argv) {
  char* aliases = NULL;
  char* neighbors = NULL;
  char* pub_address = (char*) "tcp://127.0.0.1:9999";
  char* sub_address = (char*) "tcp://127.0.0.1:9998";
  int c = 0;
  int error;

  signal(SIGPIPE,SIG_IGN);

  struct option long_options[] = {
    {"aliases", required_argument, 0, 'a'},
    {"neighbors", required_argument, 0, 'n'},
    {"pub-address", required_argument, 0, 'p'},
    {"sub-address", required_argument, 0, 's'},
    {0,0,0,0}
  };

  const char* help_string = "\
-a,  --aliases=TCH                  the location of the aliases.tch file\n\
-h,  --help                         show this message\n\
-n,  --neighbors=TCH                the location of the neighbors.tch file\n\
-p,  --pub-address=ADDRESS          the pub address, the default is tcp://127.0.0.1:9999\n\
-s,  --sub-address=ADDRESS          the pub address, the default is tcp://127.0.0.1:9998\n\
\
";
  int option_index = 0;

  while (1) {
    c = getopt_long(argc, argv, "a:n:p:s:",long_options,&option_index);

    if (c == -1)
      break;

    switch (c) {
      case 0:
        printf("%s\n",long_options[option_index].name);
        break;
      case 'a':
        printf("%s\n",optarg);
        aliases = optarg;
        break;
      case 'n':
        neighbors = optarg;
        break;
      case 'p':
        pub_address = optarg;
        break;
      case 's':
        sub_address = optarg;
        break;
      case ':':
        printf("%s",help_string);
        exit(-2);
        break;
      case 'h':
        printf("%s",help_string);
        exit(0);
        break;
      case '?':
        printf("Unknown Argument\n");
        printf("%s",help_string);
        exit(-2);
        break;
      default:
        abort();
    }
  }

  if (!aliases || !neighbors) {
    printf("%s",help_string);
    exit(-2);
  }

  __cr = new ConceptResolver(aliases, neighbors);
  for(int i=0; i < 100000000; i++) {
    m2pp::request req;
    conceptualize(req);
  }

	std::string sender_id = "82209006-86FF-4982-B5EA-D1E29E55D481";
  vector<pid_t> children;

  download(sender_id,pub_address,sub_address);

	return 0;
}

//------------------------------------------------
//-- S t a t i c    I m p l e m e n t a t i o n --
//------------------------------------------------
static std::string conceptualize(m2pp::request& req)
{
  //const char* cand = chb_rq_param_get(req,"candidates");
  char* cand = (char* )"Amazon|Apple|Steve Jobs|Google|United States|America|Yahoo|iPhone|iPad";
  char* cand_copy = NULL;

  if (!cand) 
    cand_copy = strdup("");
  else
    cand_copy = strdup(cand);

  SnippetList candidates;
  split_into_vector(candidates,cand_copy);

  ResolvedConceptList concepts;
  __cr->resolve(candidates,concepts);

  pt_node_t* result = pt_array_new();
  for(ResolvedConceptList::const_iterator ii = concepts.begin(); ii != concepts.end(); ii++) {
    resolved_concept_t conc = *ii;
    pt_node_t* entry = pt_map_new();
    pt_map_set(entry,"text_rep", pt_string_new(conc.text_rep));
    pt_map_set(entry,"concept", pt_string_new(conc.canonical));
    pt_map_set(entry,"score", pt_integer_new(conc.score));
    cout << "Concept:" << conc.text_rep << ":" << conc.canonical << ":" << conc.score <<  endl;
    pt_array_push_back(result,entry);
  }

  pt_node_t* payload = pt_map_new();
  pt_map_set(payload,"payload",result);

  char* json_str = pt_to_json(payload,0);
  pt_free_node(payload);

  string ret = json_str;
  free(json_str);
  return json_str;
}

static void split_into_vector(SnippetList& vec, char* input)
{
  if (input) {
    int len = strlen(input);
    char* snippet = (char*) input;
    for(int i=0; i < len + 1; i++) {
      if (input[i] == '|' || input[i] == '\0') {
        input[i] = '\0';
        vec.push_back(snippet);
        snippet = (char*) input + i + 1;
      }
    }
  }
}
