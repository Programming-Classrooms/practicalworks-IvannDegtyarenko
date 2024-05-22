#ifndef ALIST_HPP
#define ALIST_HPP

#include <set>
#include "../Author/author.hpp"


class AList {
private:
    std::set<Author> authorsList;
public:
    AList();
    AList(const std::set<Author>&);
    AList(const AList&);
    virtual ~AList() = default;

    void insert(const Author&);
    void emplace(const std::string&, const std::string&, const std::string&);

    AList& operator=(const AList&);
    
    bool operator==(const AList&) const;

    void erase(const std::string&, const std::string&, const std::string&);

    bool find(const Author&);

    friend std::ostream& operator<<(std::ostream&, const AList&);
};
#endif //ALIST_HPP
