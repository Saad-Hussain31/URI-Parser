
#include "uri.hpp"

namespace Uri {

    struct Uri::Impl {
        std::string scheme;
        std::string host;
        std::vector<std::string> path;

    };

    Uri::~Uri() = default;

    Uri::Uri() : impl_(new Impl){

    }
    
    bool Uri::parseFromString(const std::string& uriString) {
        //scheme
        const auto schemeEnd  = uriString.find(":");
        impl_->scheme = uriString.substr(0,schemeEnd);
        auto rest = uriString.substr(schemeEnd + 1); //rest of the str past the part already parsed

        //host
        if(rest.substr(0,2) == "//") {
            //authority
            const auto authorityEnd = rest.find("/", 2);
            impl_->host = rest.substr(2, authorityEnd - 2); //skeptical about -2
        } else {
            impl_->host.clear();
        }

        //Parse path
        while(!rest.empty()) {
            auto pathDelimiter = rest.find('/');
            if (pathDelimiter ==  std::string::npos) {
                pathDelimiter = rest.length();
            }
            impl_->path.emplace_back(rest.begin(), rest.begin() + pathDelimiter);

            rest = rest.substr(pathDelimiter + 1);
            


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
        return impl_->path;
    }

    

}//end Uri