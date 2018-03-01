#include<BnCallback.h>

status_t BnCallback::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {
    INFO("[BnCallback::onTransact] (%i) %i", code, flags);
    data.checkInterface(this);
    //data.print(PLOG); endl(PLOG);

    switch(code) {
        case CALLBACK: {
            int32_t inData = data.readInt32();
            INFO("[BnCallback::onTransact] %i", inData);
            callback(inData);    // Ignoring the fixed alert string
            ASSERT(reply != 0);
            //reply->print(PLOG); endl(PLOG);
            return NO_ERROR;
        } break;
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}
