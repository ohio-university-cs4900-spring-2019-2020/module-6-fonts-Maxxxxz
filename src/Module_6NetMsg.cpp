#include "NetMsgCreateWO.h"
#ifdef AFTR_CONFIG_USE_BOOST

#include <iostream>
#include <sstream>
#include <string>
#include "AftrManagers.h"
#include "Vector.h"
#include "WO.h"
#include "GLView.h"
#include "WorldContainer.h"
#include "Module_6NetMsg.h"
#include "GLViewModule_6.h"

using namespace Aftr;

NetMsgMacroDefinition(Module6NetMsg);

Module6NetMsg::Module6NetMsg(std::string msg, Aftr::Vector pos)
{
	this->msg = msg;
	this->vec = pos;
}

Module6NetMsg::~Module6NetMsg()
{
}

//need to write
bool Module6NetMsg::toStream(NetMessengerStreamBuffer& os) const
{
	os << this->msg;
	os << this->vec.x << this->vec.y << this->vec.z;
	return true;
}

//need to write
bool Module6NetMsg::fromStream(NetMessengerStreamBuffer& is)
{
	is >> this->msg;
	is >> this->vec.x >> this->vec.y >> this->vec.z;
	return true;
}

//need to write
void Module6NetMsg::onMessageArrived()
{

	GLViewModule_6* glView = ((GLViewModule_6*)ManagerGLView::getGLView());
	std::cout << this->toString() << std::endl;
	glView->createTextAtPos(this->msg, this->vec);

}

//need to write
std::string Module6NetMsg::toString() const
{
	std::stringstream ss;

	ss << NetMsg::toString();
	ss << "Sent payload:" << std::endl;
	ss << "Message: " << msg << std::endl;
	ss << "Vector: " << vec << std::endl;
	return ss.str();
}

#endif