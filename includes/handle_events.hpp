#ifndef HANDLE_EVENTS_HPP
# define HANDLE_EVENTS_HPP

#include <iostream>
#include "SDL.h"
#include <map>

class handle_events
{
	public:
		handle_events( void );
		~handle_events( void );

	private:
		std::map< std::string, int (*)(int value) >		_events;

};

#endif //!HANDLE_EVENTS_HPP

