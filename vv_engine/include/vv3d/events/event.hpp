#ifndef VV_EVENT_INCLUDED
#define VV_EVENT_INCLUDED

namespace vv
{

enum class EventType
{
	winclose, winrezise,
	keyup, keydown, keyrepeat,
	appupdate, apprender, apptick,
	mouseclick, mousescroll, mousemove
};

struct Event
{
	virtual EventType get_type() const = 0;
};

struct MouseMoveEvent: public Event
{
	double xpos, ypos;

	EventType get_type() const { return EventType::mousemove; }
};

struct WindowCloseEvent: public Event
{
	EventType get_type() const { return EventType::winclose; }
};

} // namespace sd

#endif