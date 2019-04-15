/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
*
*
 */

#ifndef DIFFSERV_H
#define DIFFSERV_H


#include <queue>
#include "ns3/packet.h"
#include "ns3/queue.h"


namespace ns3 {

class TraceContainer;
class DiffServ : public Queue {
public:

  DiffServ();
  virtual ~DiffServ();
  static TypeId GetTypeId (void); 
  void SetMode (DiffServ::QueueMode mode);
  DiffServ::QueueMode GetMode (void) const;
  Ptr<ns3::Packet> Schedule ();
  uint32_t Classify (Ptr<ns3::Packet>);


private: 

  virtual bool DoEnqueue (Ptr<ns3::Packet> p);
  virtual Ptr<ns3::Packet> DoDequeue (void);
  virtual Ptr<const ns3::Packet> DoPeek (void) const;
  std::queue<Ptr<ns3::Packet>> m_packets; 
  uint32_t m_maxPackets;              
  uint32_t m_maxBytes;                
  uint32_t m_bytesInQueue;            
  QueueMode m_mode;                   

}; 
} // namespace ns3

#endif /* DIFFSERV_H */
