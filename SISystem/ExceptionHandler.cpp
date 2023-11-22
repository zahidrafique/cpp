#include "ExceptionHandler.h"
#include <fstream>
#include "utilities.h"

using namespace std;

ExceptionHandler::ExceptionHandler() {
	ifstream errorFile(EXCPETIONS_FILENAME.c_str());

	if (errorFile.fail()) throw EXCEPTION_FILE_READ_ERROR;

	string name, message;
	int code;

	while (errorFile.good()) {
		errorFile >> name;
		if (errorFile.eof()) break;

		errorFile >> code;
		getline(errorFile, message);

		errorMap.insert({ code, message });
	}
}

std::string ExceptionHandler::what(int code) {
	return errorMap[code];
}