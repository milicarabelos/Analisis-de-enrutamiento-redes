#ifndef NET
#define NET

#include <string.h>
#include <omnetpp.h>
#include <packet_m.h>

using namespace omnetpp;

class TransportPacket : public cPacket
{
    struct idLists
    {
        int id;
        idLists *next;
    } idList *list;

public:
    TransportPacket(const char *name = "TransportPacket", short kind = 2) : cPacket(name, kind) {
        list = NULL;
    }

    void addIdList(int id)
    {
        // add id list to the end of the current list
        idList *aux = this->list;
        while (aux != NULL)
        {
            aux = aux->next;
        }
        idList *newId = new idList;
        newId->id = id;
        newId->next = NULL;
        aux->next = newId;
    }

    idList *getIdList()
    {
        return list;
    }
};


class Net : public cSimpleModule
{
private:
    cOutVector hopsVector;
    //  cStdDev hopsStats;
    cOutVector LnkSelectVector;
    struct idLists
    {
        int id;
        idLists *next;
    } idList *listIndex;

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

Net::Net()
{
}

Net::~Net()
{
}

void Net::initialize()
{
    hopsVector.setName("Hops");
    LnkSelectVector.setName("Lnk_Selected");
    listIndex = NULL;
    TransportPacket *pkt = new TransportPacket();
    pkt->setDestination(this->getParentModule()->getIndex());
    pkt->addIdList(this->getParentModule()->getIndex());
    send(pkt, "toLnk$o", 0);
    //  hopsStats.setName("TotalHops");
}

void Net::finish()
{
    //    recordScalar("AverageHops", hopsStats.getMean());
}

void Net::handleMessage(cMessage *msg)
{
    
    if (msg->getKind() == 2)
    {
        TransportPacket *pkt = (TransportPacket *)msg;
        
        this->bubble("recibi tipo 2, id %i", pkt->getIdList()->id);
        if (pkt->getDestination() == this->getParentModule()->getIndex())
        {
            listIndex = pkt->getIdList();
        }
        else
        {
            pkt->addIdList(this->getParentModule()->getIndex());
            send(msg, "toLnk$o", 0);
        }
    }
    else
    {

        // All msg (events) on net are packets
        Packet *pkt = (Packet *)msg;

        // If this node is the final destination, send to App

        if (pkt->getDestination() == this->getParentModule()->getIndex())
        {

            hopsVector.record(pkt->getHopCount());
            // hopsStats.collect(pkt->getHopCount());
            send(msg, "toApp$o");
        }
        // If not, forward the packet to some else... to who?
        else
        {
            // We send to link interface #0, which is the
            // one connected to the clockwise side of the ring
            // Is this the best choice? are there others?
            pkt->setHopCount(pkt->getHopCount() + 1);

            // la idea de este vector es ver que porcentaje de veces elegimos mandar por la gate 0 y cuales por
            // la gate 1 por lo tanto hay que cambiar aca cuando cambiemos la gate elegida
            LnkSelectVector.record(0);
            send(msg, "toLnk$o", 0);
        }
    }
}
