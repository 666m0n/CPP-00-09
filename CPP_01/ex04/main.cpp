#include <iostream>
#include <fstream>
#include <string>

std::string replaceInstring(std::string content, const std::string& s1,
const std::string& s2) {
	if (s1.empty() || content.find(s1) == std::string::npos) {
		return content;
	}

	std::string result;
	size_t startPos = 0;
	size_t foundPos;

	while ((foundPos = content.find(s1, startPos)) != std::string::npos) {
		result += content.substr(startPos, foundPos - startPos);
		result += s2;
		startPos = foundPos + s1.length();
	}
	result += content.substr(startPos);
	return result;
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cerr << "Usage : " << argv[0] << " <filename> <string1> string2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "Error: Cannot open input file: " << filename << std::endl;
		return 1;
	}

	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open()) {
		std::cerr << "Error: Cannot open input file: " << filename << std::endl;
		return 1;
	}

	std::string outFilename = filename + ".replace";
	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open()) {
		std::cerr << "Error: Cannot create output file: " << outFilename << std::endl;
		inFile.close();
		return 1;
	}

	std::string line;
	while (std::getline(inFile, line)) {
		std::string modifiedLine = replaceInstring(line, s1, s2);
		outFile << modifiedLine;
		if (!inFile.eof()) {
			outFile << std::endl;
		}
	}
	inFile.close();
	outFile.close();

	std::cout << "Replacement completed. Result saved in : " << outFilename << std::endl;
	return 0;
}