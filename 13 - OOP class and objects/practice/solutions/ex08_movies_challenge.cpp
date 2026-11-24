// Solution 8 - Movies challenge / Lời giải 8
#include <iostream>
#include <string>
#include <vector>

class Movie {
    std::string name;
    std::string rating;
    int watched;
public:
    Movie(std::string name, std::string rating, int watched)
        : name{name}, rating{rating}, watched{watched} {}
    Movie(const Movie &source) : Movie{source.name, source.rating, source.watched} {}
    ~Movie() {}

    void set_name(std::string n) { name = n; }
    std::string get_name() const { return name; }
    void set_rating(std::string r) { rating = r; }
    std::string get_rating() const { return rating; }
    void set_watched(int w) { watched = w; }
    int get_watched() const { return watched; }

    void increment_watched() { ++watched; }
    void display() const {
        std::cout << name << ", " << rating << ", " << watched << std::endl;
    }
};

class Movies {
    std::vector<Movie> movies;
public:
    bool add_movie(std::string name, std::string rating, int watched) {
        for (const Movie &m : movies)
            if (m.get_name() == name) return false;
        movies.push_back(Movie{name, rating, watched});
        return true;
    }
    bool increment_watched(std::string name) {
        for (Movie &m : movies)          // non-const reference: we modify it
            if (m.get_name() == name) { m.increment_watched(); return true; }
        return false;
    }
    void display() const {
        if (movies.empty()) {
            std::cout << "Sorry, no movies to display\n" << std::endl;
            return;
        }
        std::cout << "\n===================================" << std::endl;
        for (const Movie &m : movies) m.display();
        std::cout << "===================================\n" << std::endl;
    }
};

void increment_watched(Movies &movies, std::string name) {
    if (movies.increment_watched(name)) std::cout << name << " watch incremented" << std::endl;
    else std::cout << name << " not found" << std::endl;
}

void add_movie(Movies &movies, std::string name, std::string rating, int watched) {
    if (movies.add_movie(name, rating, watched)) std::cout << name << " added" << std::endl;
    else std::cout << name << " already exists" << std::endl;
}

int main() {
    Movies my_movies;
    my_movies.display();
    add_movie(my_movies, "Big", "PG-13", 2);
    add_movie(my_movies, "Star Wars", "PG", 5);
    add_movie(my_movies, "Cinderella", "PG", 7);
    my_movies.display();
    add_movie(my_movies, "Cinderella", "PG", 7);
    add_movie(my_movies, "Ice Age", "PG", 12);
    my_movies.display();
    increment_watched(my_movies, "Big");
    increment_watched(my_movies, "Ice Age");
    my_movies.display();
    increment_watched(my_movies, "XXX");
    return 0;
}
