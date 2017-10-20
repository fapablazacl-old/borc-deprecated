
#include "Version.hpp"
#include <cassert>

namespace borc {
    Version::Version(const int major) {
        this->setMajor(major);
    }

    Version::Version(const int major, const int minor) {
        this->setMajor(major)->setMinor(minor);
    }

    Version::Version(const int major, const int minor, const int revision) {
        this->setMajor(major)->setMinor(minor)->setRevision(revision);
    }
    
    Version* Version::setMajor(const int value) {
        m_major = value;

        return this;
    }
    
    Version* Version::setMinor(const int value) {
        m_minor = value;

        return this;
    }

    Version* Version::setRevision(const int value) {
        m_revision = value;

        return this;
    }

    int Version::compare(const Version *other) const {
        assert(other);

        if (*this == *other) {
            return 0;
        } else if (*this < *other) {
            return -1;
        } else if (*this > *other) {
            return 1;
        }
    }

    bool Version::operator< (const Version &other) const {
        if (m_major >= other.m_major) {
            return false;
        }

        if (m_minor >= other.m_minor) {
            return false;
        }

        if (m_revision >= other.m_revision) {
            return false;
        }

        return true;
    }

    bool Version::operator> (const Version &other) const {
        return ! (*this <= other);
    }

    bool Version::operator<= (const Version &other) const {
        return *this < other || *this == other;
    }
    
    bool Version::operator>= (const Version &other) const {
        return *this > other || *this == other;
    }

    bool Version::operator== (const Version &other) const {
        if (m_major != other.m_major) {
            return false;
        }

        if (m_minor != other.m_minor) {
            return false;
        }

        if (m_revision != other.m_revision) {
            return false;
        }

        return true;
    }

    bool Version::operator!= (const Version &other) const {
        return ! (*this == other);
    }

    std::string Version::toString() const {
        return std::to_string(m_major) + "." + std::to_string(m_minor) + "." + std::to_string(m_revision);
    }
}
