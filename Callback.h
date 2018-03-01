#ifndef CALLBACK_H
#define CALLBACK_H

#include <stdint.h>
#include <sys/types.h>
#include <utils/RefBase.h>
#include <utils/Errors.h>
#include <binder/IInterface.h>
#include "BnCallback.h"

// Function prototype for the callback that data should be sent to
typedef void (*DataCallback)(int);

class Callback: public BnCallback
{
public:
    Callback(DataCallback fn);
    ~Callback();
    virtual void callback(int32_t data);

private:
    DataCallback fn_Callback;
};


#endif // CALLBACK_H
