#include "FileManager.hpp"

#include <fstream>

#include "Generated/FileConfig.hpp"

#define MODE_READ "r"

FileManager::FileManager() : _searchDirectories({RESOURCES_DIR}) { /* Empty */ }

void FileManager::addSearchDirectory(const std::string& directory) {
	_searchDirectories.push_back(directory);
}

std::string FileManager::fullpathForFileName(const std::string& fileName) {
	// auto it = _fullpathCache.find(fileName);
	// if (it != _fullpathCache.cend()) {
	// 	return it->second;
	// }

	// struct stat buffer;
	// for (const std::string& searchDir : _searchDirectories) {
	// 	std::string tentativeFilePath = searchDir + "/" + fileName;
	// 	if (stat(tentativeFilePath.c_str(), &buffer) == 0) {
	// 		_fullpathCache[fileName] = tentativeFilePath;
	// 		return tentativeFilePath;
	// 	}
	// }

	// return "";
}

std::string FileManager::dataForFilePath(const std::string& filePath) {
	// std::string fullFilePath = fullpathForFileName(filePath);
	// if (fullFilePath.empty()) { return ""; }
	
	// // Open File
	// std::ifstream inputFile(fullFilePath);
	// if (!inputFile.is_open()) { return ""; }

	// // Allocate necessary memory
	// std::string data;
	// inputFile.seekg(0, std::ios::end);
	// data.reserve(static_cast<const unsigned>(inputFile.tellg()));
	// inputFile.seekg(0, std::ios::beg);

	// // Get the file data
	// data.assign((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

	// return data;
}