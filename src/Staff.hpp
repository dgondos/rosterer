#ifndef __STAFF_H__
#define __STAFF_H__

#include <vector>
#include <string>

namespace Rosterer
{
    class Staff
    {
    public:
        Staff(const std::string& name, const std::string& site);
        const std::string& getName() const;
        const std::string& getSite() const;
    private:
        const std::string _name;
        const std::string _site;
    };
}

#endif