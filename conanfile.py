from conans import ConanFile, CMake


class RDFParser(ConanFile):
    name = "sparql-queryGraph"
    version = "0.9"
    author = "DICE Group <info@dice-research.org>"
    homepage = "https://github.com/dice-group/rdf-parser"
    url = homepage
    license = "AGPL"
    topics = ("dice-group", "RDF", "parser", "semantic web")
    settings = "build_type", "compiler", "os", "arch"
    generators = "cmake", "cmake_find_package", "cmake_paths"
    exports = "LICENSE"
    exports_sources = "include/*", "CMakeLists.txt", "cmake/dummy-config.cmake.in"
    requires="rdf-parser/0.11@dice-group/stable","gtest/1.8.1"
    no_copy_source = True

    def package(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.install()

    def package_id(self):
        self.info.header_only()
