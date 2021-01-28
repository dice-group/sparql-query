import re, os
from conans.tools import load
from conans import ConanFile, CMake, tools


class RDFParser(ConanFile):
    name = "sparql-query"
    author = "DICE Group <info@dice-research.org>"
    homepage = "https://github.com/dice-group/sparql-query"
    url = homepage
    license = "AGPL"
    topics = ("dice-group", "SPARQL", "query", "semantic web")
    settings = "build_type", "compiler", "os", "arch"
    generators = "cmake", "cmake_find_package", "cmake_paths"
    exports = "LICENSE"
    exports_sources = "include/*", "CMakeLists.txt", "cmake/dummy-config.cmake.in"
    requires="rdf-parser/0.13.0@dice-group/stable","gtest/1.8.1"
    no_copy_source = True

    def set_version(self):
        if not hasattr(self, 'version') or self.version is None:
            cmake_file = load(os.path.join(self.recipe_folder, "CMakeLists.txt"))
            self.version = re.search("project\(sparql-query VERSION (.*)\)", cmake_file).group(1)

    def package(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.install()

    def package_id(self):
        self.info.header_only()

        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
        try:
            with open("README.md") as file:
                self.description = file.read()
        except Exception as err:
            self.description = str(err)
