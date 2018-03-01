#ifndef ICALLBACK_H
#define ICALLBACK_H

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
#include <Common.h>

using namespace android;

class ICallback : public IInterface {
    public:
        enum {
            CALLBACK = IBinder::FIRST_CALL_TRANSACTION,
        };
        // Sends a user-provided value to the service
        virtual void callback(int32_t data)          = 0;

        DECLARE_META_INTERFACE(Callback);  // Expands to 5 lines below:
        //static const android::String16 descriptor;
        //static android::sp<IDemo> asInterface(const android::sp<android::IBinder>& obj);
        //virtual const android::String16& getInterfaceDescriptor() const;
        //IDemo();
        //virtual ~IDemo();
};

#endif // ICALLBACK_H
