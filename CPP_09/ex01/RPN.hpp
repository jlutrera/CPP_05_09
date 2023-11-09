#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>

class RPN
{
	private:
		std::stack<int> 		_stack;
		std::stack<std::string> _stack_str;
	public:
		RPN();
		RPN(RPN const &other);
		~RPN();
		RPN &operator=(RPN const &other);

		void 		push(int value);
		int 		pop();
		void 		push_str(std::string value);
		std::string pop_str();
		int 		getSize() const;
		int 		getSize2() const;
		void 		operation(char op);
		void 		process(char *c);
		void 		print(int pren);
};

#endif
