
#include "Version.hpp"
#include <cassert>
#include <stdexcept>

namespace borc {
    Version::Version(const int major) {
        setMajor(major);
    }

    Version::Version(const int major, const int minor) {
        setMajor(major).setMinor(minor);
    }

    Version::Version(const int major, const int minor, const int revision) {
        setMajor(major).setMinor(minor).setRevision(revision);
    }
    
    Version& Version::setMajor(const int value) {
        if (value < 0) {
            throw std::invalid_argument("Argument should be non-negative");
        }

        m_major = value;

        return *this;
    }
    
    Version& Version::setMinor(const int value) {
        if (value < 0) {
            throw std::invalid_argument("Argument should be non-negative");
        }

        m_minor = value;

        return *this;
    }

    Version& Version::setRevision(const int value) {
        if (value < 0) {
            throw std::invalid_argument("Argument should be non-negative");
        }

        m_revision = value;

        return *this;
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
        if (m_major == other.m_major) {
            if (m_minor == other.m_minor) {
                return m_revision < other.m_revision;
            } else {
                return m_minor < other.m_minor;
            }
        } else {
            return m_major < other.m_major;
        }
    }

    bool Version::operator> (const Version &other) const {
        if (m_major == other.m_major) {
            if (m_minor == other.m_minor) {
                return m_revision > other.m_revision;
            } else {
                return m_minor > other.m_minor;
            }
        } else {
            return m_major > other.m_major;
        }
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
