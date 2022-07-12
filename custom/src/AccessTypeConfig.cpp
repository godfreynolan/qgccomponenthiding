#include "AccessTypeConfig.h"

AccessType CURRENT_USER_ACCESS_TYPE = Basic;
//AccessType CURRENT_USER_ACCESS_TYPE = Expert;
//AccessType CURRENT_USER_ACCESS_TYPE = Factory;

AccessType getInitialUserAccessType() {
    return CURRENT_USER_ACCESS_TYPE;
}
