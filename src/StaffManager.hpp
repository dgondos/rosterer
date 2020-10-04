#ifndef __STAFF_MANAGER_H__
#define __STAFF_MANAGER_H__

#include <vector>
#include <string>

namespace Rosterer
{
    class StaffManager
    {
    public:
        static StaffManager& instance();
        StaffManager(StaffManager const&) = delete;
        void operator=(StaffManager const&) = delete;

        const std::vector<std::string>& getAllStaff() const;
    private:
        StaffManager();

        std::vector<std::string> _staff;
    };
}

#endif