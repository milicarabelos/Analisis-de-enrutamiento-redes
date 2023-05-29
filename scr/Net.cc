#ifndef NET
#define NET

#include <string.h>
#include <omnetpp.h>
#include <packet_m.h>

using namespace omnetpp;

class Net: public cSimpleModule {
private:
    cOutVector hopsVector;
//  cStdDev hopsStats;
    cOutVector LnkSelectVector;

public:
    Net();
    virtual ~Net();
protected:
    virtual void initialize();
    virtual void finish();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Net);

#endif /* NET */

Net::Net() {
}

Net::~Net() {
}

void Net::initialize() {
    hopsVector.setName("Hops");
    LnkSelectVector.setName("Lnk_Selected");
//  hopsStats.setName("TotalHops");
}

void Net::finish() {
//    recordScalar("AverageHops", hopsStats.getMean());
}

void Net::handleMessage(cMessage *msg) {

    // All msg (events) on net are packets
    Packet *pkt = (Packet *) msg;

    // If this node is the final destination, send to App
    if (pkt->getDestination() == this->getParentModule()->getIndex()) {

        hopsVector.record(pkt->getHopCount());
        //hopsStats.collect(pkt->getHopCount());
        send(msg, "toApp$o");
    }
    // If not, forward the packet to some else... to who?
    else {
        // We send to link interface #0, which is the
        // one connected to the clockwise side of the ring
        // Is this the best choice? are there others?
        pkt->setHopCount(pkt->getHopCount()+1);

        //la idea de este vector es ver que porcentaje de veces elegimos mandar por la gate 0 y cuales por
        //la gate 1 por lo tanto hay que cambiar aca cuando cambiemos la gate elegida
        LnkSelectVector.record(0);
        send(msg, "toLnk$o", 0);
    }
}
