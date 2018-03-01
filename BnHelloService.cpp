
#include <BnHelloService.h>
#include <ICallback.h>

status_t BnHelloService::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    switch(code) {
        case TRANSACTION_PING_SERVER: {
            INFO("[BnHelloService::onTransact] TRANSACTION_PING_SERVER\n");
            CHECK_INTERFACE(IHelloService, data, reply);
            int a = data.readInt32();
            pingServer(a);
            reply->writeInt32(0);
            return NO_ERROR;
        }
        case TRANSACTION_SET_CALLBACK: {
            INFO("[BnHelloService::onTransact] TRANSACTION_SET_CALLBACK\n");
            CHECK_INTERFACE(IHelloService, data, reply);
            android::sp<ICallback> pCallback = interface_cast<ICallback>(data.readStrongBinder());
            setCallback(pCallback);
            reply->writeInt32(0);
            return NO_ERROR;
        }
        default: {
            return BBinder::onTransact(code, data, reply, flags);
        }
    }
    // should be unreachable
    return NO_ERROR;
}
