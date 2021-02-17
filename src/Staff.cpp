#include <Staff.hpp>

using namespace Rosterer;

Staff::Staff(const std::string& name, const std::string& site)
    : _name(name), _site(site) {
}

const std::string& Staff::getName() const {
    return _name;
}

const std::string& Staff::getSite() const {
    return _site;
}