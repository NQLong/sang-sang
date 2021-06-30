#ifndef A5E133C7_0FFD_4881_A867_A9CF8C6B5893
#define A5E133C7_0FFD_4881_A867_A9CF8C6B5893
#include "BookRequest.h"
class RequestManage
{
public:
    RequestManage(){}
    virtual ~RequestManage() {}
    virtual bool add_request(BookRequest)=0;
    virtual bool add_request()=0;
    virtual bool remove_request()=0;
    virtual bool remove_request(BookRequest)=0;
    virtual BookRequest *get_request(int id)=0;
    virtual BookRequest *pick_request()=0;
    virtual bool select_request()=0;
    virtual void requests_list()=0;
};
#endif /* A5E133C7_0FFD_4881_A867_A9CF8C6B5893 */
