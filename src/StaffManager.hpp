#ifndef __STAFF_MANAGER_H__
#define __STAFF_MANAGER_H__

#include <vector>
#include <string>

namespace Rosterer
{
    class StaffManager
    {
    public:
        static const std::vector<std::string>& getAllStaff();
    };
}

#endif