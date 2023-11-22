#pragma once

enum class Role {Invalid, Student, Staff, Faculty};

const std::string USER_FILENAME = "C:\\Temp\\CmpSci236\\sis_user.txt";
const std::string COURSE_FILENAME = "C:\\Temp\\CmpSci236\\sis_course.txt";
const std::string GRADE_FILENAME = "C:\\Temp\\CmpSci236\\sis_grade.txt";
const std::string EXCPETIONS_FILENAME = "C:\\Temp\\CmpSci236\\sis_exceptions.txt";

const int EXCEPTION_FILE_READ_ERROR = 1;

const int INVALID_STUDENT_ID = 1000;
const int INVALID_COURSE_ID = 1001;
const int AUTHENTICATION_FAILED_ERROR = 2000;
const int AUTHORIZATION_FAILED_ERROR = 2001;

const int USER_DATA_FILE_READ_ERROR = 2101;
const int COURSE_DATA_FILE_READ_ERROR = 2102;
const int GRADE_DATA_FILE_READ_ERROR = 2103;
const int GRADE_DATA_FILE_WRITE_ERROR = 2104;

const int STUDENT_DATA_MISMATCH = 3000;

const int INVALID_REQUEST_OPTION = 4000;