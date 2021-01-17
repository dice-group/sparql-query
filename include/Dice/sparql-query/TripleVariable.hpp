
#ifndef SPARQL_QUERY_TRIPLEVARIABLE_HPP
#define SPARQL_QUERY_TRIPLEVARIABLE_HPP

namespace Dice::SPARQL {
    class TripleVariable {
    private:
        std::string name;
        bool is_anonym;

    public:
        explicit TripleVariable(std::string var_name, bool anonym = false) : name{std::move(var_name)},
                                                                             is_anonym{anonym} {}

        inline bool operator==(const TripleVariable &rhs) const {
            return name == rhs.name;
        }

        inline bool operator!=(const TripleVariable &rhs) const {
            return name != rhs.name;
        }

        inline bool operator<(const TripleVariable &rhs) const {
            return name < rhs.name;
        }

        inline bool operator>(const TripleVariable &rhs) const {
            return name > rhs.name;
        }

        std::string getName() const {
            return name;
        }

        bool isAnonym() const {
            return is_anonym;
        }

    };
}
#endif //SPARQL_QUERY_TRIPLEVARIABLE_HPP
