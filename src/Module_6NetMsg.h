#pragma once

#include "NetMsg.h"
#ifdef AFTR_CONFIG_USE_BOOST

namespace Aftr
{

	class Module6NetMsg : public NetMsg
	{
	public:
		NetMsgMacroDeclaration(Module6NetMsg);


		Module6NetMsg(){}
		Module6NetMsg(std::string msg, Aftr::Vector pos);
		virtual ~Module6NetMsg();
		virtual bool toStream(NetMessengerStreamBuffer& os) const;
		virtual bool fromStream(NetMessengerStreamBuffer& is);
		virtual void onMessageArrived();
		virtual std::string toString() const;
	private:
		std::string msg;
		Aftr::Vector vec;
	};
}
#endif