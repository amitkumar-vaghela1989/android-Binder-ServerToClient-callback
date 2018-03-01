#define LOG_TAG "HelloClient"

#include <utils/Log.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#include "IHelloService.h"
#include <Callback.h>

using namespace android;

// Callback function
void MyDataCallback(int val)
{
    INFO("HelloClient : MyDataCallback val:%d\n", val);
    return;
}

int main()
{
    sp<IHelloService> service = interface_cast<IHelloService>(defaultServiceManager()->getService(String16("hello")));

    // Ping server from client To server
    INFO("HelloClient : ping server\n");
    service->pingServer(99);

    // create binder for callback in client and pass callback function to object
    sp<ICallback> cb(new Callback(MyDataCallback));

    // Set callback in Sever so it can call client asynchronously
    INFO("HelloClient : assign callback to server\n");
    service->setCallback(cb);

    android::ProcessState::self()->startThreadPool();

    // just running client to get callback
    while(1)
    {
        sleep(1);
    }

    return 0;
}
