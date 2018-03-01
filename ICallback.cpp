#include <ICallback.h>
#include <BpCallback.h>

//IMPLEMENT_META_INTERFACE(Callback, "Callback");
// Macro above expands to code below. Doing it by hand so we can log ctor and destructor calls.
const android::String16 ICallback::descriptor("Callback");
const android::String16& ICallback::getInterfaceDescriptor() const {
    return ICallback::descriptor;
}
android::sp<ICallback> ICallback::asInterface(const android::sp<android::IBinder>& obj) {
    android::sp<ICallback> intr;
    if (obj != NULL) {
        intr = static_cast<ICallback*>(obj->queryLocalInterface(ICallback::descriptor).get());
        if (intr == NULL) {
            intr = new BpCallback(obj);
        }
    }
    return intr;
}
ICallback::ICallback() { INFO("ICallback::ICallback()"); }
ICallback::~ICallback() { INFO("ICallback::~ICallback()"); }
// End of macro expansion
