#include <BpHelloService.h>

int BpHelloService::pingServer(int a)
{
    ALOGD("BpHelloService::pingServer\n");
    Parcel data, reply;
    data.writeInterfaceToken(IHelloService::getInterfaceDescriptor());
    data.writeInt32(a);
    //remote()->transact(IHelloService::TRANSACTION_PING_SERVER, data, &reply);
    remote()->transact(TRANSACTION_PING_SERVER, data, &reply);
    return reply.readInt32();
}

int BpHelloService::setCallback(android::sp<ICallback>& oCallback)
{
    ALOGD("BpHelloService::setCallback\n");
    Parcel data, reply;
    data.writeInterfaceToken(IHelloService::getInterfaceDescriptor());
    data.writeStrongBinder(oCallback->asBinder());
    remote()->transact(TRANSACTION_SET_CALLBACK, data, &reply, IBinder::FLAG_ONEWAY);    // asynchronous call
    return reply.readInt32();
}
