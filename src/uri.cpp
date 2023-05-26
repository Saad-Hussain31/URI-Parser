
#include "uri.hpp"
#include <string>
#include <vector>




namespace Uri {

    struct Uri::Impl {
        std::string pathDelimiter;
        std::string scheme;
        std::string host;
        std::vector<std::string> path;

    };

    Uri::~Uri() = default;

    Uri::Uri() : impl_(new Impl){

    }

    void Uri::setPathDelimiter(const std::string& newPathDelimiter) {
        impl_->pathDelimiter = newPathDelimiter;
    }
    
    bool Uri::parseFromString(const std::string& uriString) {
        //scheme
        const auto schemeEnd  = uriString.find(':');
        impl_->scheme = uriString.substr(0,schemeEnd);
        auto rest = uriString.substr(schemeEnd + 1); //rest of the str past the part already parsed

        //host
        if(rest.substr(0,2) == "//") {
            //authority
            const auto authorityEnd = rest.find(impl_->pathDelimiter, 2);
            impl_->host = rest.substr(2, authorityEnd - 2); //skeptical about -2
            rest = rest.substr(authorityEnd);
        } else {
            impl_->host.clear();
        }

        //Parse path
        impl_->path.clear();
        if(rest == impl_->pathDelimiter) {
            impl_->path.push_back("");
        } else if (!rest.empty()) {
            for(;;) {
                auto pathDelimiter = rest.find(impl_->pathDelimiter);
                if (pathDelimiter ==  std::string::npos) {
                    impl_->path.push_back(rest);
                    break;
                } else {
                    impl_->path.emplace_back(rest.begin(), rest.begin() + pathDelimiter);
                    rest = rest.substr(pathDelimiter + impl_->pathDelimiter.length());           
                }
            }
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