#ifndef BNCALLBACK_H
#define BNCALLBACK_H

#include<ICallback.h>

class BnCallback : public BnInterface<ICallback> {
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
};

#endif // BNCALLBACK_H
