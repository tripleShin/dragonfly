#ifndef LOGGING_H
#define LOGGING_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

namespace drf {
	class logging
	{
	public:
		logging();
		std::string setUpDirectory();
		void logString( std::string text, std::string directoryName);
		~logging();
		
	};
} // drf

#endif // LOGGING_H
