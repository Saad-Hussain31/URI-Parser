
#include "uri.hpp"

namespace Uri {

    struct Uri::Impl {
        std::string scheme;
        std::string host;

    };

    Uri::~Uri() = default;

    Uri::Uri() : impl_(new Impl){

    }
    
    bool Uri::parseFromString(const std::string& uriString) {
        const auto schemeEnd  = uriString.find(":");
        impl_->scheme = uriString.substr(0,schemeEnd);
        if(uriString.substr(schemeEnd,2) == "//") {
            //authority
            const auto authorityEnd = uriString.find("/", schemeEnd + 2);
            impl_->host = uriString.substr(schemeEnd + 2, authorityEnd - (schemeEnd + 2));
        } else {
            impl_->host.clear();
        }
        return true;
    }


    std::string Uri::getScheme() const {
        return impl_->scheme;
    }
    
    std::string Uri::getHost() const {
        return impl_->host;
    }
    
    std::vector<std::string> Uri::getPath() const{
        return {"", "foo", "bar"};
    }

    

}//end Uri