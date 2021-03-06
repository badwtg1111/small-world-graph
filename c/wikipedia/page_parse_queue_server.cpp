// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "PageParseQueue.h"
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>

#include <deque>
#include "thread_safe_queue.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;

using boost::shared_ptr;

#define CHUNK_SIZE 1000
#define QUEUE_SIZE 50000

class PageParseQueueHandler : virtual public PageParseQueueIf {
 public:
  PageParseQueueHandler() {
    // Your initialization goes here
  }

  void dequeue(std::vector<RawPage> & _return) {
    int amount_to_dequeue = (raw_pages_.size() > CHUNK_SIZE) ? CHUNK_SIZE : raw_pages_.size();
    for(int i=0; i < amount_to_dequeue; i++) {
      RawPage unit = raw_pages_.front();
      raw_pages_.pop_front();
      _return.push_back(unit);
    }
    cout << "Dequeued " << _return.size() << " work units. " << raw_pages_.size() << " Remain." << endl;
  }

  void enqueue(const std::vector<RawPage> & pages) {
    if (raw_pages_.size() + pages.size() > QUEUE_SIZE) {
      cout << "Queue is Full: Throwing Exception" << endl;
      QueueFullException qfe;
      throw qfe;
    }
    for(vector<RawPage>::const_iterator ii = pages.begin(); ii != pages.end(); ii++) {
      raw_pages_.push_back(*ii);
    }
    cout << "Enqueued " << pages.size() << " work units. " << raw_pages_.size() << " in queue." << endl;
  }
 protected:
  deque<RawPage> raw_pages_;
};

int main(int argc, char **argv) {
  int port = 10010;
  shared_ptr<PageParseQueueHandler> handler(new PageParseQueueHandler());
  shared_ptr<TProcessor> processor(new PageParseQueueProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

