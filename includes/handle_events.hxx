#include <iostream>
#include "handle_events.hpp"

template <typename T>
handle_events<T>::handle_events( void )
{
	return ;
}

template <typename T>
handle_events<T>::~handle_events( void )
{

	return ;
}

template <typename T>
void		handle_events<T>::add_key_event(int type, int key, bool (*func)(T))
{
	if(type == SDL_KEYDOWN)
		this->_key_down[key] = func;
	else if(type == SDL_KEYUP)
		this->_key_up[key] = func;
}

template <typename T>
void		handle_events<T>::add_event(int type, bool (*func)(const SDL_Event &, T))
{
	this->_events[type] = func;
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
	typename std::map< int, bool (*)(T) >::iterator	it;

	(void)perso;
	it = this->_key_up.find(e.key.keysym.sym);
	if (it != this->_key_up.end())
		it->second( perso );
	return (true);
}

template <typename T>
bool	handle_events<T>::key_down( const SDL_Event &e, T perso )
{
	typename std::map< int, bool (*)(T) >::iterator	it;

	(void)perso;
	it = this->_key_down.find(e.key.keysym.sym);
	if (it != this->_key_down.end())
		it->second( perso );
	return (true);
}

template <typename T>
bool	handle_events<T>::_handle_special_events( const SDL_Event &e, T perso )
{
	if(e.type == SDL_KEYDOWN)
		this->key_down(e, perso);
	else if(e.type == SDL_KEYUP)
		this->key_up(e, perso);
	return(true);
}

template <typename T>
bool	handle_events<T>::check( T perso )
{
	SDL_Event e;
	typename std::map< int, bool (*)(const SDL_Event &, T) >::iterator it;

	if (SDL_PollEvent(&e))
	{
		it = this->_events.find(e.type);
	   	_handle_special_events(e, perso);
	    if (it != this->_events.end())
	    	return (it->second(e, perso));
//	    else
//	    	//undifined event type
	}
	return(true);
}