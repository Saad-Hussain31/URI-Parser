#pragma once
#include <string>
#include <vector>
#include <memory>

namespace Uri {

    class Uri {
        public:
            ~Uri();
            Uri(const Uri&) = delete;
            Uri(Uri&&) = delete;
            Uri& operator=(const Uri&) = delete;
            Uri& operator=(Uri&&) = delete;

        public:
            Uri();
            void setPathDelimiter(const std::string& newPathDelimiter);
            bool parseFromString(const std::string& uriString);
            std::string getScheme() const;
            std::string getHost() const;
            std::vector<std::string> getPath() const;

        private:
            struct Impl;
            std::unique_ptr<Impl> impl_;


    };

} //end Uri