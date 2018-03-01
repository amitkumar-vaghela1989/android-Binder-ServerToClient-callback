#include<BpCallback.h>

void BpCallback::callback(int32_t push_data) {
    Parcel data, reply;
    data.writeInterfaceToken(ICallback::getInterfaceDescriptor());
    data.writeInt32(push_data);
    INFO("BpCallback::callback\n");
    remote()->transact(CALLBACK, data, &reply);
}
