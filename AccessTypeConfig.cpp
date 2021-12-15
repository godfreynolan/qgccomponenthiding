#include "AccessTypeConfig.h"

AccessType CURRENT_USER_ACCESS_TYPE = Basic

AccessType getInitialUserAccessType() {
    return CURRENT_USER_ACCESS_TYPE;
}