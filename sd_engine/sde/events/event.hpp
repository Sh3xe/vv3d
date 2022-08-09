#pragma once

namespace sd
{

enum class EventType
{
	winclose, winrezise,
	keyup, keydown, keyrepeat,
	appupdate, apprender, apptick,
	mouseclick, mousescroll, mousemove
};

class Event
{
public:
	Event();
	~Event();

	virtual EventType get_type() = 0;

};

} // namespace sd