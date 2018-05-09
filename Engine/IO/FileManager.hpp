#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class FileManager {
public:
	FileManager();
	void addSearchDirectory(const std::string& directory);

	std::string fullpathForFileName(const std::string& fileName);
	std::string dataForFilePath(const std::string& filePath);

private:
	std::unordered_map<std::string, std::string> _fullpathCache;
	std::vector<std::string> _searchDirectories;
};
