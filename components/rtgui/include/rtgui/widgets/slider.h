#ifndef __RTGUI_SLIDER_H__
#define __RTGUI_SLIDER_H__

#include <rtgui/rtgui.h>
#include <rtgui/widgets/widget.h>

/** Gets the type of a slider */
#define RTGUI_SLIDER_TYPE       (rtgui_slider_type_get())
/** Casts the object to an rtgui_slider */
#define RTGUI_SLIDER(obj)       (RTGUI_OBJECT_CAST((obj), RTGUI_SLIDER_TYPE, rtgui_slider_t))
/** Checks if the object is an rtgui_slider */
#define RTGUI_IS_SLIDER(obj)    (RTGUI_OBJECT_CHECK_TYPE((obj), RTGUI_SLIDER_TYPE))

struct rtgui_slider
{
	struct rtgui_widget parent;

	/* widget private data */
	rt_size_t min, max, value, ticks;
	rt_size_t thumb_width;

	int orient;
};
typedef struct rtgui_slider rtgui_slider_t;

rtgui_type_t *rtgui_slider_type_get(void);

struct rtgui_slider* rtgui_slider_create(rt_size_t min, rt_size_t max, int orient);
void rtgui_slider_destroy(struct rtgui_slider* slider);

rt_bool_t rtgui_slider_event_handler(struct rtgui_widget* widget, struct rtgui_event* event);

void rtgui_slider_set_range(struct rtgui_slider* slider, rt_size_t min, rt_size_t max);
void rtgui_slider_set_value(struct rtgui_slider* slider, rt_size_t value);
void rtgui_slider_set_orientation(struct rtgui_slider* slider, int orientation);

rt_size_t rtgui_slider_get_value(struct rtgui_slider* slider);

#endif