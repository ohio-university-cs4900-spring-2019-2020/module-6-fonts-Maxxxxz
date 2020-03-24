#pragma once

#include "GLView.h"
#include "NetMessengerClient.h"

namespace Aftr
{
   class Camera;

/**
   \class GLViewModule_6
   \author Scott Nykl 
   \brief A child of an abstract GLView. This class is the top-most manager of the module.

   Read \see GLView for important constructor and init information.

   \see GLView

    \{
*/

class GLViewModule_6 : public GLView
{
public:
   static GLViewModule_6* New( const std::vector< std::string >& outArgs );
   virtual ~GLViewModule_6();
   virtual void updateWorld(); ///< Called once per frame
   virtual void loadMap(); ///< Called once at startup to build this module's scene
   virtual void createModule_6WayPoints();
   virtual void onResizeWindow( GLsizei width, GLsizei height );
   virtual void onMouseDown( const SDL_MouseButtonEvent& e );
   virtual void onMouseUp( const SDL_MouseButtonEvent& e );
   virtual void onMouseMove( const SDL_MouseMotionEvent& e );
   virtual void onKeyDown( const SDL_KeyboardEvent& key );
   virtual void onKeyUp( const SDL_KeyboardEvent& key );
   void createTextAtPos(std::string msg, Aftr::Vector pos);
   void beginMessageSend();
private:
	NetMessengerClient* client;
protected:
   GLViewModule_6( const std::vector< std::string >& args );
   virtual void onCreate();   
};

/** \} */

} //namespace Aftr
