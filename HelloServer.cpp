#define LOG_TAG "HelloServer"

#include <utils/Log.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#include "HelloService.h"

using namespace android;

android::sp<ICallback> pMyCallback;
int main()
{
    printf("HelloServer : HelloServer is starting\n");

    sp<ProcessState> proc(ProcessState::self());
    ProcessState::self()->startThreadPool();

    // create HellowService
    defaultServiceManager()->addService(String16("hello"), new HelloService);

    printf("HelloServer : Successfully register service: hello\n");
    printf("HelloServer : Ready to joinThreadPool\n");

    //get number from user
    while(1)
    {
        INFO ("HelloServer : Enter number to send client :");
        int num;
        scanf("%d", &num);
        INFO ("HelloServer : number is %d", num);
        INFO("HellowServer callback to client\n");
        pMyCallback->callback(num);
    }

    IPCThreadState::self()->joinThreadPool();

    return 0;
}
