#include <BnCallback.h>

#define LOG_TAG "callback"

#include <sys/wait.h>
#include <unistd.h>
#include <cutils/log.h>
#include <binder/BinderService.h>
#include "Callback.h"

Callback::Callback(DataCallback fn):fn_Callback(fn)
{
}

Callback::~Callback()
{
}

void Callback::callback(int32_t data)
{
    INFO("[HelloService::callback]\n");
    fn_Callback(data);
    return;
}
