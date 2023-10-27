#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include "colors.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif