#include <iostream>
#include <string>

// Function to check if the file has .crypt extension
bool hasCryptExtension(const std::string& filename) {
    std::string extension = ".crypt";
    if (filename.length() >= extension.length()) {
        return (0 == filename.compare(filename.length() - extension.length(), extension.length(), extension));
    } else {
        return false;
    }
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

    std::cout << "File recognized: " << filename << std::endl;
    // Proceed with compilation logic here (to be added later)

    return 0;
}
