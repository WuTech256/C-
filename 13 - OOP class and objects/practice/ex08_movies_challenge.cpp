// Exercise 8 - Section 13 Challenge: Movies (single-file version)
// EN: Implement Movie and Movies so that main() produces the expected output.
// VI: Cài đặt Movie và Movies để main() cho ra kết quả như mong đợi.
#include <iostream>
#include <string>
#include <vector>

class Movie {
    std::string name;    // movie name / tên phim
    std::string rating;  // G, PG, PG-13, R
    int watched;         // times watched / số lần xem
public:
    // TODO: Movie(std::string name, std::string rating, int watched);
    // TODO: copy constructor (delegating) / copy constructor ủy quyền
    // TODO: const getters, setters
    // TODO: void increment_watched();
    // TODO: void display() const;   // prints: name, rating, watched
};

class Movies {
    std::vector<Movie> movies;
public:
    // TODO: bool add_movie(std::string name, std::string rating, int watched);
    //       -> false if name already exists / false nếu tên đã có
    // TODO: bool increment_watched(std::string name);
    //       -> false if not found / false nếu không tìm thấy
    // TODO: void display() const;
    //       -> "Sorry, no movies to display" if empty / nếu rỗng
};

void increment_watched(Movies &movies, std::string name) {
    // if (movies.increment_watched(name)) std::cout << name << " watch incremented" << std::endl;
    // else std::cout << name << " not found" << std::endl;
}

void add_movie(Movies &movies, std::string name, std::string rating, int watched) {
    // if (movies.add_movie(name, rating, watched)) std::cout << name << " added" << std::endl;
    // else std::cout << name << " already exists" << std::endl;
}

int main() {
    Movies my_movies;
    // my_movies.display();                          // Sorry, no movies to display
    add_movie(my_movies, "Big", "PG-13", 2);
    add_movie(my_movies, "Star Wars", "PG", 5);
    add_movie(my_movies, "Cinderella", "PG", 7);
    // my_movies.display();
    add_movie(my_movies, "Cinderella", "PG", 7);     // already exists
    add_movie(my_movies, "Ice Age", "PG", 12);
    increment_watched(my_movies, "Big");
    increment_watched(my_movies, "Ice Age");
    // my_movies.display();
    increment_watched(my_movies, "XXX");             // not found
    return 0;
}
