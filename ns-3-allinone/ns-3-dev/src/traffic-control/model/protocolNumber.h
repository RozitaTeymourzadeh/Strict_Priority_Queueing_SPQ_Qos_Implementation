
#ifndef PROTOCOL_NUMBER_H
#define PROTOCOL_NUMBER_H


#include "ns3/log.h"
#include "ns3/integer.h"
#include "ns3/ppp-header.h"
#include "ns3/pointer.h"
#include "queue-disc.h"
#include "filterElement.h"

namespace ns3 {

class ProtocolNumber: public FilterElement {
  
public:

  static TypeId GetTypeId (void);

  ProtocolNumber ();
  ~ProtocolNumber ();
  

  bool Match (Ptr<Packet> packet);


private:
  uint32_t value;  

};

} // namespace ns3

#endif /* ProtocolNumber */