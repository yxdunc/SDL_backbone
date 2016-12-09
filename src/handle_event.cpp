#include <iostream>
#include "handle_event.hpp"

template <typename T>
handle_event::handle_event( void )
{
	this->_event[SDL_QUIT] = handle_event::quit();
	this->_event[SDL_KEYDOWN] = handle_event::key_down();
	this->_event[SDL_KEYUP] = handle_event::key_up();
	return ;
}

template <typename T>
handle_event::~handle_event( void )
{

	return ;
}

template <typename T>
void		add_key_event(std::string type, std::string key, bool (*func)(T))
{
	if(type == SDL_KEYDOWN)
		this->_key_down[key] = func;
	else if(type == SDL_KEYUP)
		this->_key_up[key] = func;
}

template <typename T>
void		add_event(std::string type, bool (*func)(const SDL_Event &, T))
{
	this->_event[type] = func;
}

template <typename T>
bool	handle_event::quit( const SDL_Event &e, T perso )
{
	return (false);
}

template <typename T>
bool	handle_event::key_up( const SDL_Event &e, T perso )
{
	bool (*func)( void );

	func = this->_key_up[e.key.keysym.sym];
	if (func != this->_key_down.end())
		func();
	return (true);
}

template <typename T>
bool	handle_event::key_down( const SDL_Event &e, T perso )
{
	bool (*func)( void );

	func = this->_key_down[e.key.keysym.sym];
	if (func != this->_key_down.end())
		func();
	return (true);
}

template <typename T>
SDL_Event	handle_event::check( T perso )
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