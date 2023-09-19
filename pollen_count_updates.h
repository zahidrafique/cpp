#pragma once

namespace cmpsci236_fall2023 {
	const std::string FILENAME = "C:\\Temp\\CmpSci236\\pollen_count_updates.txt";

	const int INPUT_FILE_STREAM_EXCEPTION = 1000;
	const int OUTPUT_FILE_STREAM_EXCEPTION = 1001;

	const std::string INVALID_POLLEN_READING = "Error: Invalid pollen reading!";

	void read_data(int[], int SIZE);
	int accumulate_write_data(int[], int, int);

	void handle_exceptions(int);
}
