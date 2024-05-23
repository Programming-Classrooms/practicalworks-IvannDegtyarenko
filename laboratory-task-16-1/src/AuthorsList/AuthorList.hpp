#ifndef AUTHORLIST_HPP
#define AUTHORLIST_HPP

#include <set>
#include "../Author/Author.hpp"


class AuthorList {
private:
    std::set<Author> authorsList;
public:
    AuthorList();
    AuthorList(const std::set<Author>&);
    AuthorList(const AuthorList&);
    virtual ~AuthorList() = default;

    void insert(const Author&);
    void emplace(const std::string&, const std::string&, const std::string&);

    AuthorList& operator=(const AuthorList&);
    
    bool operator==(const AuthorList&) const;

    void erase(const std::string&, const std::string&, const std::string&);

    bool find(const Author&);

    friend std::ostream& operator<<(std::ostream&, const AuthorList&);
};
#endif //AUTHORLIST_HPP
