
#include <catch.hpp>

#include <borc/pom/Source.hpp>
#include <borc/FileType.hpp>
#include <borc/FileTypeRegistryImpl.hpp>

TEST_CASE("FileTypeRegistryImpl Test Case", "borc::FileTypeRegistryImpl") {
    borc::FileType fileType{"Java Files", {".java", ".class"}};
    borc::FileType fileType2{"C++ Source Files", {".cpp", ".cc", ".cxx", ".c++"}};

    SECTION("addFileType method should") {
        SECTION("append the C++ File Type correctly") {
            borc::FileTypeRegistryImpl registry;

            auto cppFileType = registry.addFileType("C++ Source File", {".cpp", ".cc", ".cxx", ".c++"});

            REQUIRE(cppFileType != nullptr);
            REQUIRE(cppFileType->name == "C++ Source File");
            REQUIRE(cppFileType->extensions.size() == 4);
            REQUIRE(cppFileType->extensions[0] == ".cpp");
            REQUIRE(cppFileType->extensions[1] == ".cc");
            REQUIRE(cppFileType->extensions[2] == ".cxx");
            REQUIRE(cppFileType->extensions[3] == ".c++");
        }

        SECTION("append the Java File Type correctly") {
            borc::FileTypeRegistryImpl registry;

            auto javaFileType = registry.addFileType("Java Files", {".java", ".class"});

            REQUIRE(javaFileType != nullptr);
            REQUIRE(javaFileType->name == "Java Files");
            REQUIRE(javaFileType->extensions.size() == 2);
            REQUIRE(javaFileType->extensions[0] == ".java");
            REQUIRE(javaFileType->extensions[1] == ".class");
        }

        SECTION("return a different file type instance for each invocation") {
            borc::FileTypeRegistryImpl registry;

            auto cppFileType = registry.addFileType("C++ Source File", {".cpp", ".cc", ".cxx", ".c++"});
            auto javaFileType = registry.addFileType("Java Files", {".java", ".class"});

            REQUIRE(cppFileType != javaFileType);
        }
    }

    SECTION("getFileType method should (TODO)") {
        // virtual const FileType* getFileType(const Source *source) const override
    }
}
