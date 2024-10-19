//why the fuck am i doing this??
#include <iostream>
#include <fstream>
#include <string>

// to check if the file has .crypt extension
bool hasCryptExtension(const std::string& filename) {
    std::string extension = ".crypt";
    if (filename.length() >= extension.length()) {
        return (0 == filename.compare(filename.length() - extension.length(), extension.length(), extension));
    } else {
        return false;
    }
}

// Function to check if a line is a comment
bool isCommentLine(const std::string& line) {
    std::string trimmedLine = line;
    trimmedLine.erase(0, trimmedLine.find_first_not_of(" \t"));  // Trim leading whitespace
    return trimmedLine.rfind("//", 0) == 0;  // Check if line starts with //
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: cryptex_compiler <filename.crypt>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    
    // Check if the file has the correct extension
    if (!hasCryptExtension(filename)) {
        std::cerr << "Error: File must have a .crypt extension." << std::endl;
        return 1;
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::cout << "Compiling: " << filename << std::endl;

    std::string line;
    while (std::getline(file, line)) {
        if (isCommentLine(line)) {
            continue;  // Ignore the comment line
        }

        // Process the line (put the compile logic shit here)
        std::cout << "Processing line: " << line << std::endl;
    }

    file.close();
    return 0;
}
