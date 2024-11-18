#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void display_titles(const std::string& filename) {
    /*空欄１：適切なストリームの定義*/
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Cannot open the file.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string author, title, year, publisher;

        // 各フィールドをカンマで区切って読み取る
        if (std::getline(iss,author,',')&&std::getline(iss,title,',')&&std::getline(iss,year,',')&&std::getline(iss,publisher,',')) {
            // タイトルを出力する
            std::cout << title << "\n";
        }
    }
}

void add_reference(const std::string& filename) {
    /*空欄３：ファイル出力ストリームの定義*/
    std::ofstream file(filename,std::ios::app);
    if (!file) {
        std::cerr << "Cannot open the file.\n";
        return;
    }

    std::string new_reference;
    std::cout << "Please add new references (format: Author,Title,Publication Year,Publisher): ";
    std::getline(std::cin,new_reference);

    // ファイルの末尾に追加する
    file << new_reference << "\n";
    std::cout << "New references have been added.\n";
}

void search_by_author(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Cannot open the file.\n";
        return;
    }

    std::string search_author;
    std::cout << "Enter the author name to search: ";
    std::getline(std::cin,search_author);

    std::string line;
    bool found = false;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string author, title, year, publisher;

        if (std::getline(iss, author, ',') &&
            std::getline(iss, title, ',') &&
            std::getline(iss, year, ',') &&
            std::getline(iss, publisher, ',')) {

            // 著者名が一致するか確認する
            if (author == search_author) {
                std::cout << title << "\n";
                found = true;
            }
        }
    }
    if (!found) {
        std::cout << "No references found for the specified author.\n";
    }
}

int main() {
    std::string filename = "References.txt";
    std::string choice;

    do {
        std::cout << "Select a function: (d: Display Titles, a: Add New Reference, s: Search by Author, q: Quit)\n> ";
        std::getline(std::cin, choice);

        if (choice == "d") {
            std::cout << "Reference Titles:\n";
            display_titles(filename);
        }
        else if (choice == "a") {
            add_reference(filename);
        }
        else if (choice == "s") {
            search_by_author(filename);
        }
        else if (choice == "q") {
            std::cout << "Exiting the program.\n";
        }
        else {
            std::cout << "Invalid choice. Please select again.\n";
        }
    } while (choice != "q");

    return 0;
}
