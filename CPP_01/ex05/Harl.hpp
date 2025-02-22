#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
	private:
		typedef void (Harl::*MemberFunctionPtr)(void);

		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

		static const std::string levels[4];
		static const MemberFunctionPtr functions[4];

	public:
		Harl(void);
		~Harl(void);

		void complain(std::string level);
};

#endif