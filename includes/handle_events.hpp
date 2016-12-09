#ifndef HANDLE_EVENTS_HPP
# define HANDLE_EVENTS_HPP

#include <iostream>
#include "SDL.h"
#include <map>

template <typename T>
class handle_events
{
	public:
		handle_events( );
		~handle_events( void );

		SDL_Event	check(int value);
		void		add_key_event(std::string type, std::string key, bool (*func)(T));
		void		add_event(std::string type, bool (*func)(const SDL_Event &, T));

	private:
		bool	quit(int value);
		std::map< std::string, bool (*)(const SDL_Event &, T) >	_events;
		std::map< std::string, bool (*)(T) >					_key_down;
		std::map< std::string, bool (*)(T) >					_key_up;

};

#endif //!HANDLE_EVENTS_HPP

