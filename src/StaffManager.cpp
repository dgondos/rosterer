#include <StaffManager.hpp>

using namespace Rosterer;

const std::vector<std::string>& StaffManager::getAllStaff() {
    static const std::vector<std::string> hardcodedStaff {"Ahmed", "Daniel G", "Hari", "Jeremy", "Mohamed", "Nagesha", "Rahul", "Roniit", "Shithali", "Thilo", "Valentin", "Vijay"};
    return hardcodedStaff;
}