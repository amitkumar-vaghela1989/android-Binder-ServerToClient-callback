#ifndef BNHELLOSERVICE_H
#define BNHELLOSERVICE_H

#include <IHelloService.h>

class BnHelloService: public BnInterface<IHelloService> {
public:
    virtual status_t onTransact(uint32_t code, const Parcel& data,
            Parcel* reply, uint32_t flag = 0);
};

#endif // BNHELLOSERVICE_H
