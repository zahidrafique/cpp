#pragma once

enum class Role {Invalid, Student, Staff, Faculty};

const std::string USER_FILENAME = "C:\\Temp\\CmpSci236\\sis_user.txt";
const std::string COURSE_FILENAME = "C:\\Temp\\CmpSci236\\sis_course.txt";
const std::string GRADE_FILENAME = "C:\\Temp\\CmpSci236\\sis_grade.txt";

const int USER_DATA_FILE_READ_ERROR = 2101;
const int COURSE_DATA_FILE_READ_ERROR = 2102;
const int GRADE_DATA_FILE_READ_ERROR = 2103;
const int GRADE_DATA_FILE_WRITE_ERROR = 2104;

const int STUDENT_DATA_MISMATCH = 3000;

const int INVALID_REQUEST_OPTION = 4000;