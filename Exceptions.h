/** Exceptions.h
 * define some exceptions
 * Author: zclaiqcc
 * Blog: zclaiqcc.github.io
 * Github: github.com/zclaiqcc
 * Email: zclaiqcc@gmail.com
 */

#include<new>

#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

 //Throw NoMem exception when failed to new something.
class NoMem {
public:
	NoMem() = default;
};

void my_new_handler() {
	throw NoMem();
}

std::new_handler Old_Handler_ = std::set_new_handler(my_new_handler);

class OutOfBounds {
public:
	OutOfBounds() = default;
};

class BadInput() {
	BadInput() = default;
}

#endif