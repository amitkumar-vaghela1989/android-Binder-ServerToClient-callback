#define LOG_TAG "HelloService"

#include <sys/wait.h>
#include <unistd.h>

#include <cutils/log.h>
#include <binder/BinderService.h>

#include "HelloService.h"
#include <Common.h>

extern android::sp<ICallback> pMyCallback;

HelloService::HelloService()
{
}

HelloService::~HelloService()
{
}

int HelloService::pingServer(int a)
{
    INFO("[HelloService::pingServer] :%d", a);
    return 0;
}

int HelloService::setCallback(android::sp<ICallback>& oCallback)
{
    INFO("[HHelloService::setCallback] callback is assigned from client\n");
    pCallback = oCallback;

    //assign access to global variable
    pMyCallback = oCallback;
    return 0;
}
