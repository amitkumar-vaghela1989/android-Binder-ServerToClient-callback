#ifndef BPHELLOSERVICE_H
#define BPHELLOSERVICE_H

#include <binder/IInterface.h>
#include <binder/IBinder.h>
#include <binder/Parcel.h>
#include <IHelloService.h>

class BpHelloService: public android::BpInterface<IHelloService>
{
public:
    BpHelloService(const sp<IBinder>& impl)
        : BpInterface<IHelloService>(impl)
    {
    }
    virtual int pingServer(int);
    virtual int setCallback(android::sp<ICallback>& oCallback);
};

#endif // BPHELLOSERVICE_H
