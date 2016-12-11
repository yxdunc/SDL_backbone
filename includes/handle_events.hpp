#ifndef HANDLE_EVENTS_HPP
# define HANDLE_EVENTS_HPP

#include <iostream>
#include "SDL.h"
#include <map>

template <typename T>
class handle_events
{
	public:
		handle_events( void );
		~handle_events( void );

		/* check new event */
		bool	check(T perso);

		/* add event */
		void		add_key_event(int type, int key, bool (*func)(T));
		void		add_event(int type, bool (*func)(const SDL_Event &, T));

	private:
		/* preset event functions */
		bool	quit( const SDL_Event &e, T perso );
		bool	key_up( const SDL_Event &e, T perso );
		bool	key_down( const SDL_Event &e, T perso );
		/**/

		bool	_handle_special_events(const SDL_Event &e, T perso);

		std::map< int, bool (*)(const SDL_Event &, T) >	_events;
		std::map< int, bool (*)(T) >					_key_down;
		std::map< int, bool (*)(T) >					_key_up;

};

#include "handle_events.hxx"

#endif //!HANDLE_EVENTS_HPP

