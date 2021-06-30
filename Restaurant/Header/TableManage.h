#ifndef F66EFE8D_E229_45AD_96EB_924878FFA468
#define F66EFE8D_E229_45AD_96EB_924878FFA468

#include "Table.h"

class TableManage
{
public:
    virtual bool add_table(Table) = 0;
    virtual bool add_table() = 0;
    virtual bool remove_table() = 0;
    virtual bool remove_table(Table) = 0;
    virtual Table *get_table(int id) = 0;
    virtual Table *pick_table() = 0;
    virtual void table_list() = 0;
    virtual bool select_table() = 0;
};

#endif /* F66EFE8D_E229_45AD_96EB_924878FFA468 */
