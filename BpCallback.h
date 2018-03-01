#ifndef BPCALLBACK_H
#define BPCALLBACK_H

#include <ICallback.h>

class BpCallback : public BpInterface<ICallback> {
    public:
        BpCallback(const sp<IBinder>& impl) : BpInterface<ICallback>(impl) {
            ALOGD("BpCallback::BpCallback()\n");
        }
        virtual void callback(int32_t push_data);
};

#endif // BPCALLBACK_H
