#ifndef IHELLOSERVICE_H
#define IHELLOSERVICE_H

#include <stdint.h>
#include <sys/types.h>
#include <utils/RefBase.h>
#include <utils/Errors.h>
#include <binder/IInterface.h>
#include <ICallback.h>
#include <stdint.h>
#include <sys/types.h>
#include <binder/Parcel.h>
#include <binder/IMemory.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

using namespace android;

class IHelloService: public IInterface {
public:
    enum {
        TRANSACTION_PING_SERVER = IBinder::FIRST_CALL_TRANSACTION,
        TRANSACTION_SET_CALLBACK
    };

    // Ping server client to server call
    virtual int pingServer(int) = 0;
    // Setcallback function by client To Server
    virtual int setCallback(android::sp<ICallback>& oCallback) = 0;

    DECLARE_META_INTERFACE(HelloService);  // Expands to 5 lines below:
    //static const android::String16 descriptor;
    //static android::sp<IDemo> asInterface(const android::sp<android::IBinder>& obj);
    //virtual const android::String16& getInterfaceDescriptor() const;
    //IDemo();
    //virtual ~IDemo();
};

#endif // IHELLOSERVICE_H
