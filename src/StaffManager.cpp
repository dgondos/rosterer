#include <StaffManager.hpp>

using namespace Rosterer;

StaffManager& StaffManager::instance() {
    static StaffManager instance;
    return instance;
}

StaffManager::StaffManager() {
    _staff = {"Ahmed", "Daniel G", "Hari", "Jeremy", "Mohamed", "Nagesha", "Rahul", "Roniit", "Shithali", "Thilo", "Valentin", "Vijay"};
}

const std::vector<std::string>& StaffManager::getAllStaff() const {
    return _staff;
}