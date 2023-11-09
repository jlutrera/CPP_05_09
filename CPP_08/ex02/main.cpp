#include "MutantStack.hpp"
#include <list>

void msprint(MutantStack<int> &mstack)
{
	MutantStack<int>::iterator ite;

	std::cout << CYAN << "mstack: " << RESET << std::endl;
	for (ite = mstack.end(); ite != mstack.begin(); ite--)
	{
		std::cout << "       " << *(ite - 1) << std::endl;
	}
}

int main()
{
	MutantStack<int> mstack;

	std::cout << "******** MUTANTSTACK TEST *******" << std::endl;
	std::cout << "**********  push test  **********" << std::endl;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(737);
	mstack.push(0);	
	msprint(mstack);
	std::cout << "**********   pop test  **********" << std::endl;
	mstack.pop();
	msprint(mstack);
	std::cout << "******* size and top test *******" << std::endl;
	std::cout << YELLOW << "size: " << mstack.size() << RESET << std::endl;
	std::cout << YELLOW << "top: " << mstack.top() << RESET << std::endl;
	
	std::cout << "\n****** copy test in a stack ******" << std::endl;	
	std::stack<int> s(mstack);
	std::cout << CYAN << "stack: " << RESET << std::endl;
	while (!s.empty())
	{
		std::cout << "       " << s.top() << std::endl;
		s.pop();
	}

	std::cout << "\n****** the same in a list *******" << std::endl;
	std::list<int> l;
	l.push_front(5);
	l.push_front(17);
	l.push_front(3);
	l.push_front(737);
	l.push_front(0);
	l.pop_front();
	std::list<int>::iterator it;
	std::cout << CYAN << "list: " << RESET << std::endl;
	for (it = l.begin(); it != l.end(); it++)
		std::cout << "       " << *it << std::endl;
	return (0);
}
