/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 */
#ifndef SiteRelationships_H
#define SiteRelationships_H

#include <TProcessor.h>
#include "site_relationships_types.h"



class SiteRelationshipsIf {
 public:
  virtual ~SiteRelationshipsIf() {}
  virtual void sites_close_to(std::vector<int32_t> & _return, const int32_t site_id) = 0;
  virtual void distances(std::vector<SiteRelationship> & _return, const std::vector<int32_t> & site_ids) = 0;
};

class SiteRelationshipsNull : virtual public SiteRelationshipsIf {
 public:
  virtual ~SiteRelationshipsNull() {}
  void sites_close_to(std::vector<int32_t> & /* _return */, const int32_t /* site_id */) {
    return;
  }
  void distances(std::vector<SiteRelationship> & /* _return */, const std::vector<int32_t> & /* site_ids */) {
    return;
  }
};

class SiteRelationships_sites_close_to_args {
 public:

  SiteRelationships_sites_close_to_args() : site_id(0) {
  }

  virtual ~SiteRelationships_sites_close_to_args() throw() {}

  int32_t site_id;

  struct __isset {
    __isset() : site_id(false) {}
    bool site_id;
  } __isset;

  bool operator == (const SiteRelationships_sites_close_to_args & rhs) const
  {
    if (!(site_id == rhs.site_id))
      return false;
    return true;
  }
  bool operator != (const SiteRelationships_sites_close_to_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SiteRelationships_sites_close_to_args & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class SiteRelationships_sites_close_to_pargs {
 public:


  virtual ~SiteRelationships_sites_close_to_pargs() throw() {}

  const int32_t* site_id;

  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class SiteRelationships_sites_close_to_result {
 public:

  SiteRelationships_sites_close_to_result() {
  }

  virtual ~SiteRelationships_sites_close_to_result() throw() {}

  std::vector<int32_t>  success;

  struct __isset {
    __isset() : success(false) {}
    bool success;
  } __isset;

  bool operator == (const SiteRelationships_sites_close_to_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SiteRelationships_sites_close_to_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SiteRelationships_sites_close_to_result & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class SiteRelationships_sites_close_to_presult {
 public:


  virtual ~SiteRelationships_sites_close_to_presult() throw() {}

  std::vector<int32_t> * success;

  struct __isset {
    __isset() : success(false) {}
    bool success;
  } __isset;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);

};

class SiteRelationships_distances_args {
 public:

  SiteRelationships_distances_args() {
  }

  virtual ~SiteRelationships_distances_args() throw() {}

  std::vector<int32_t>  site_ids;

  struct __isset {
    __isset() : site_ids(false) {}
    bool site_ids;
  } __isset;

  bool operator == (const SiteRelationships_distances_args & rhs) const
  {
    if (!(site_ids == rhs.site_ids))
      return false;
    return true;
  }
  bool operator != (const SiteRelationships_distances_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SiteRelationships_distances_args & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class SiteRelationships_distances_pargs {
 public:


  virtual ~SiteRelationships_distances_pargs() throw() {}

  const std::vector<int32_t> * site_ids;

  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class SiteRelationships_distances_result {
 public:

  SiteRelationships_distances_result() {
  }

  virtual ~SiteRelationships_distances_result() throw() {}

  std::vector<SiteRelationship>  success;

  struct __isset {
    __isset() : success(false) {}
    bool success;
  } __isset;

  bool operator == (const SiteRelationships_distances_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SiteRelationships_distances_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SiteRelationships_distances_result & ) const;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(apache::thrift::protocol::TProtocol* oprot) const;

};

class SiteRelationships_distances_presult {
 public:


  virtual ~SiteRelationships_distances_presult() throw() {}

  std::vector<SiteRelationship> * success;

  struct __isset {
    __isset() : success(false) {}
    bool success;
  } __isset;

  uint32_t read(apache::thrift::protocol::TProtocol* iprot);

};

class SiteRelationshipsClient : virtual public SiteRelationshipsIf {
 public:
  SiteRelationshipsClient(boost::shared_ptr<apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  SiteRelationshipsClient(boost::shared_ptr<apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr<apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr<apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr<apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void sites_close_to(std::vector<int32_t> & _return, const int32_t site_id);
  void send_sites_close_to(const int32_t site_id);
  void recv_sites_close_to(std::vector<int32_t> & _return);
  void distances(std::vector<SiteRelationship> & _return, const std::vector<int32_t> & site_ids);
  void send_distances(const std::vector<int32_t> & site_ids);
  void recv_distances(std::vector<SiteRelationship> & _return);
 protected:
  boost::shared_ptr<apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr<apache::thrift::protocol::TProtocol> poprot_;
  apache::thrift::protocol::TProtocol* iprot_;
  apache::thrift::protocol::TProtocol* oprot_;
};

class SiteRelationshipsProcessor : virtual public apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<SiteRelationshipsIf> iface_;
  virtual bool process_fn(apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid);
 private:
  std::map<std::string, void (SiteRelationshipsProcessor::*)(int32_t, apache::thrift::protocol::TProtocol*, apache::thrift::protocol::TProtocol*)> processMap_;
  void process_sites_close_to(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot);
  void process_distances(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot);
 public:
  SiteRelationshipsProcessor(boost::shared_ptr<SiteRelationshipsIf> iface) :
    iface_(iface) {
    processMap_["sites_close_to"] = &SiteRelationshipsProcessor::process_sites_close_to;
    processMap_["distances"] = &SiteRelationshipsProcessor::process_distances;
  }

  virtual bool process(boost::shared_ptr<apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr<apache::thrift::protocol::TProtocol> poprot);
  virtual ~SiteRelationshipsProcessor() {}
};

class SiteRelationshipsMultiface : virtual public SiteRelationshipsIf {
 public:
  SiteRelationshipsMultiface(std::vector<boost::shared_ptr<SiteRelationshipsIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~SiteRelationshipsMultiface() {}
 protected:
  std::vector<boost::shared_ptr<SiteRelationshipsIf> > ifaces_;
  SiteRelationshipsMultiface() {}
  void add(boost::shared_ptr<SiteRelationshipsIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void sites_close_to(std::vector<int32_t> & _return, const int32_t site_id) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->sites_close_to(_return, site_id);
        return;
      } else {
        ifaces_[i]->sites_close_to(_return, site_id);
      }
    }
  }

  void distances(std::vector<SiteRelationship> & _return, const std::vector<int32_t> & site_ids) {
    uint32_t sz = ifaces_.size();
    for (uint32_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->distances(_return, site_ids);
        return;
      } else {
        ifaces_[i]->distances(_return, site_ids);
      }
    }
  }

};



#endif
