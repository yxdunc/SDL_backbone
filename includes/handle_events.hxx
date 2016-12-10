#include <iostream>
#include "handle_events.hpp"

template <typename T>
handle_events<T>::handle_events( void )
{
	this->_event[SDL_QUIT] = handle_events::quit();
	this->_event[SDL_KEYDOWN] = handle_events::key_down();
	this->_event[SDL_KEYUP] = handle_events::key_up();
	return ;
}

template <typename T>
handle_events<T>::~handle_events( void )
{

	return ;
}

template <typename T>
void		handle_events<T>::add_key_event(std::string type, std::string key, bool (*func)(T))
{
	if(type == "KEYDOWN")
		this->_key_down[key] = func;
	else if(type == "KEYUP")
		this->_key_up[key] = func;
}

template <typename T>
void		handle_events<T>::add_event(std::string type, bool (*func)(const SDL_Event &, T))
{
	this->_event[type] = func;
}

template <typename T>
bool	handle_events<T>::quit( const SDL_Event &e, T perso )
{
	(void)e;(void)perso;
	return (false);
}

template <typename T>
bool	handle_events<T>::key_up( const SDL_Event &e, T perso )
{
	bool (*func)( T );

	(void)e;(void)perso;
	func = this->_key_up[e.key.keysym.sym];
	if (func != this->_key_down.end())
		func( perso );
	return (true);
}

template <typename T>
bool	handle_events<T>::key_down( const SDL_Event &e, T perso )
{
	bool (*func)( T );

	(void)perso;
	func = this->_key_down[e.key.keysym.sym];
	if (func != this->_key_down.end())
		func( perso );
	return (true);
}

template <typename T>
SDL_Event	handle_events<T>::check( T perso )
{
	SDL_Event e;
	bool (*func)(const SDL_Event &, T perso);

	if (SDL_PollEvent(&e))
	{
		func = this->_event[e.type];
	    if (func == this->_event.end())
	    {
	    	//undifined event type
	    }
	    else
	    	func(perso);
	}
	return(e);
}