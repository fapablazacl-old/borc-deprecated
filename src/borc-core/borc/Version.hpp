
#ifndef __borc_version_hpp__
#define __borc_version_hpp__

#include <string>

namespace borc {
    class Version {
    public:
        explicit Version() {}

        explicit Version(const int major);

        explicit Version(const int major, const int minor);

        explicit Version(const int major, const int minor, const int revision);

        int getMajor() const {
            return m_major;
        }

        int getMinor() const {
            return m_minor;
        }

        int getRevision() const {
            return m_revision;
        }
        
        Version* setMajor(const int value);

        Version* setMinor(const int value);

        Version* setRevision(const int value);

        int compare(const Version *other) const;

        bool operator< (const Version &other) const;

        bool operator> (const Version &other) const;

        bool operator<= (const Version &other) const;
        
        bool operator>= (const Version &other) const;

        bool operator== (const Version &other) const;

        bool operator!= (const Version &other) const;

        std::string toString() const;

    private:
        int m_major = 0;
        int m_minor = 0;
        int m_revision = 0;
    };
}

#endif 
