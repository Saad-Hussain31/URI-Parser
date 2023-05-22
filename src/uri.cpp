
#include "uri.hpp"

namespace Uri {

    struct Uri::Impl {

    };

    Uri::~Uri() = default;

    Uri::Uri() : impl_(new Impl){

    }
    
    bool Uri::parseFromString(const std::string& uriString) {
        return true;
    }


    std::string Uri::getScheme() const {
        return "xyz";
    }
    
    std::string Uri::getHost() const {
        return "xyz";
    }
    
    std::vector<std::string> Uri::getPath() const{
        return {};
    }

    

}//end Uri