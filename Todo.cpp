#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    int counter = 0;
    std::string read;
    std::ifstream todoIn("../TodoList.txt");
    if (todoIn.is_open()) {
        if (argc == 1) {
            std::cout << "Command line arguments:" << std::endl;
            std::cout << "-l   Lists all the tasks." << std::endl;
            std::cout << "-a   Adds a new task." << std::endl;
            std::cout << "-r   Removes an task." << std::endl;
            std::cout << "-c   Completes an task." << std::endl;
            return 0;
        }
        if (argc == 2) {
            std::string argument(argv[1]);
            if (argument == "-l") {
                while (getline(todoIn, read)) {
                    std::cout << std::to_string(++counter) + "- " + read << std::endl;
                }if(counter == 0){
                    std::cout << "No TODOs for today :)" << std::endl;
                }
                return 0;
            }
        }
            if(argc == 3){
                std::string argument(argv[1]);
                if(argument == "-a"){
                    std::ofstream todoOut("../TodoList.txt", std::ios::app);
                    todoOut << "\n" << argv[2];
                }
            }
            else {
                std::cout << "not supported argument" << std::endl;
                return 2;
            }

    } else {
        std::cout << "File cannot be found!" << std::endl;
    }
    return 0;
}