#ifndef HELLOSERVICE_H
#define HELLOSERVICE_H

#include <stdint.h>
#include <sys/types.h>
#include <utils/RefBase.h>
#include <utils/Errors.h>
#include <binder/IInterface.h>
#include "BnHelloService.h"

class HelloService: public BnHelloService
{
public:
    HelloService();
    ~HelloService();
    android::sp<ICallback> pCallback;
    virtual int pingServer(int);
    virtual int setCallback(android::sp<ICallback>& oCallback);
};

#endif // HELLOSERVICE_H
