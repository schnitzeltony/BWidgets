/* ImageVSlider.hpp
 * Copyright (C) 2018 - 2022  Sven Jähnichen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef BWIDGETS_IMAGEVSLIDER_HPP_
#define BWIDGETS_IMAGEVSLIDER_HPP_

#include "ImageVMeter.hpp"
#include "Supports/Clickable.hpp"
#include "Supports/Draggable.hpp"
#include "Supports/Scrollable.hpp"
#include "../BEvents/WheelEvent.hpp"

#ifndef BWIDGETS_DEFAULT_IMAGEVSLIDER_WIDTH
#define BWIDGETS_DEFAULT_IMAGEVSLIDER_WIDTH BWIDGETS_DEFAULT_IMAGEVMETER_WIDTH
#endif

#ifndef BWIDGETS_DEFAULT_IMAGEVSLIDER_HEIGHT
#define BWIDGETS_DEFAULT_IMAGEVSLIDER_HEIGHT BWIDGETS_DEFAULT_IMAGEVMETER_HEIGHT
#endif

namespace BWidgets
{

/**
 *  @brief  %ImageVSlider widget.
 *
 *  %ImageVSlider is a Valueable widget derived from ImageVMeter. It displays 
 *  a value as a vertical scale in the same way as ImageVMeter and 
 *  additionally supports user interaction via Clickable, Draggable, and 
 *  Scrollable.
 */
class ImageVSlider :	public ImageVMeter, 
						public Clickable, 
						public Draggable, 
						public Scrollable
{
public:

	/**
	 * @brief  Constructs an empty %ImageVSlider object.
	 * 
	 */
	ImageVSlider ();

	/**
	 *  @brief  Constructs an empty %ImageVSlider object.
	 *  @param URID  URID.
	 *  @param title  %Widget title.
	 */
	ImageVSlider (const uint32_t urid, const std::string& title);

	/**
	 *  @brief  Creates a %ImageVSlider with default size.
	 *  @param staticImage  Filename of the static passive content image.
	 *  @param staticAnchors  Anchor points of the static passive content 
	 *  (std::pair of position for the min value and position of the max 
	 *  value).
	 *  @param activeImage  Optional, filename of the static active content 
	 *  image.
	 *  @param activeAnchor  Optional, anchor point of the static active
	 *  content which fits to the min value.
	 *  @param dynamicImage  Optional, filename of the dynamic content image.
	 *  @param dynamicAnchor  Optional, anchor point of the dynamic content
	 *  (position anchored along the min value to max value line).
	 *  @param value  Optional, initial value.
	 *  @param min  Optional, lower value limit.
	 *  @param max  Optional, upper value limit.
	 *  @param step  Optional, value increment steps.
	 *  @param urid  Optional, URID (default = URID_UNKNOWN_URID).
	 *  @param title  Optional, %Widget title (default = "").
	 *
	 *  Note: It's mandatory to provide an image for the static passive content
	 *  @a staticImage (background, labels, ...) and its anchor points for the
	 *  min value and the max value. The image area of @a staticImage MUST
	 *  cover ALL possible positions of the static active content 
	 *  @a activeImage and the dynamic content @a dynamicImage.
	 */
	ImageVSlider	(const std::string staticImage, const std::pair<BUtilities::Point<>, BUtilities::Point<>> staticAnchors,
					 std::string activeImage = "", BUtilities::Point<> activeAnchor = {0,0},
					 std::string dynamicImage = "", BUtilities::Point<> dynamicAnchor = {0,0},
					 double value = 0.0, double min = 0.0, double max = 1.0, double step = 0.0, 
					 uint32_t urid = URID_UNKNOWN_URID, std::string title = "");

	/**
	 *  @brief  Creates a %ImageVSlider.
	 *  @param x  %ImageVSlider X origin coordinate.
	 *  @param y  %ImageVSlider Y origin coordinate.
	 *  @param width  %ImageVSlider width.
	 *  @param height  %ImageVSlider height.
	 *  @param staticImage  Filename of the static passive content image.
	 *  @param staticAnchors  Anchor points of the static passive content 
	 *  (std::pair of position for the min value and position of the max 
	 *  value).
	 *  @param activeImage  Optional, filename of the static active content 
	 *  image.
	 *  @param activeAnchor  Optional, anchor point of the static active
	 *  content which fits to the min value.
	 *  @param dynamicImage  Optional, filename of the dynamic content image.
	 *  @param dynamicAnchor  Optional, anchor point of the dynamic content
	 *  (position anchored along the min value to max value line).
	 *  @param value  Optional, initial value.
	 *  @param min  Optional, lower value limit.
	 *  @param max  Optional, upper value limit.
	 *  @param step  Optional, value increment steps.
	 *  @param transferFunc  Optinonal, function to transfer a value from an
	 *  external context to the internal context.
	 *  @param reTransferFunc  Optinonal, function to transfer a value from the
	 *  internal context to an external context.
	 *  @param urid  Optional, URID (default = URID_UNKNOWN_URID).
	 *  @param title  Optional, %ImageVSlider title (default = "").
	 *
	 *  Note: It's mandatory to provide an image for the static passive content
	 *  @a staticImage (background, labels, ...) and its anchor points for the
	 *  min value and the max value. The image area of @a staticImage MUST
	 *  cover ALL possible positions of the static active content 
	 *  @a activeImage and the dynamic content @a dynamicImage.
	 */
	ImageVSlider	(const double x, const double y, const double width, const double height, 
					 const std::string staticImage, const std::pair<BUtilities::Point<>, BUtilities::Point<>> staticAnchors,
					 std::string activeImage = "", BUtilities::Point<> activeAnchor = {0,0},
					 std::string dynamicImage = "", BUtilities::Point<> dynamicAnchor = {0,0},
					 double value = 0.0, double min = 0.0, double max = 1.0, double step = 0.0, 
					 std::function<double (const double& x)> transferFunc = ValueTransferable<double>::noTransfer,
					 std::function<double (const double& x)> reTransferFunc = ValueTransferable<double>::noTransfer,
					 uint32_t urid = URID_UNKNOWN_URID, std::string title = "");

	/**
	 *  @brief  Creates a clone of the %ImageVSlider. 
	 *  @return  Pointer to the new %ImageVSlider.
	 *
	 *  Creates a clone of this %ImageVSlider by copying all properties. But NOT its
	 *  linkage.
	 *
	 *  Allocated heap memory needs to be freed using @c delete if the clone
	 *  in not needed anymore!
	 */
	virtual Widget* clone () const override; 

	/**
	 *  @brief  Copies from another %ImageVSlider. 
	 *  @param that  Other %ImageVSlider.
	 *
	 *  Copies all properties from another %ImageVSlider. But NOT its linkage.
	 */
	void copy (const ImageVSlider* that);

	/**
     *  @brief  Method called when pointer button pressed.
     *  @param event  Passed Event.
     *
     *  Overridable method called from the main window event scheduler when
     *  pointer button pressed. Sets the value and calls the widget static 
	 *  callback function.
     */
    virtual void onButtonPressed (BEvents::Event* event) override;

	/**
     *  @brief  Method called upon pointer drag.
     *  @param event  Passed Event.
     *
     *  Overridable method called from the main window event scheduler upon
     *  a pointer drag. Changes the value and calls the widget static callback
	 *  function.
     */
    virtual void onPointerDragged (BEvents::Event* event) override;
	
	/**
     *  @brief  Method called upon (mouse) wheel scroll.
     *  @param event  Passed Event.
     *
     *  Overridable method called from the main window event scheduler upon
     *  a (mouse) wheel scroll. Increases or decreases the value and calls the
	 *  widget static callback function.
     */
    virtual void onWheelScrolled (BEvents::Event* event) override;
};

inline ImageVSlider::ImageVSlider () :
	ImageVSlider	(0.0, 0.0, BWIDGETS_DEFAULT_IMAGEVSLIDER_WIDTH, BWIDGETS_DEFAULT_IMAGEVSLIDER_HEIGHT,
					 "", std::pair<BUtilities::Point<>, BUtilities::Point<>> ({0,0}, {0,0}),
					 "", BUtilities::Point<> (0,0),
					 "", BUtilities::Point<> (0,0),
					 0.0, 0.0, 1.0, 0.0, 
					 ValueTransferable<double>::noTransfer, ValueTransferable<double>::noTransfer, 
					 URID_UNKNOWN_URID, "")
{

}

inline ImageVSlider::ImageVSlider (const uint32_t urid, const std::string& title) : 
	ImageVSlider	(0.0, 0.0, BWIDGETS_DEFAULT_IMAGEVSLIDER_WIDTH, BWIDGETS_DEFAULT_IMAGEVSLIDER_HEIGHT,
					 "", std::pair<BUtilities::Point<>, BUtilities::Point<>> ({0,0}, {0,0}),
					 "", BUtilities::Point<> (0,0),
					 "", BUtilities::Point<> (0,0),
					 0.0, 0.0, 1.0, 0.0, 
					 ValueTransferable<double>::noTransfer, ValueTransferable<double>::noTransfer, 
					 urid, title)
{

}

inline ImageVSlider::ImageVSlider (const std::string staticImage, const std::pair<BUtilities::Point<>, BUtilities::Point<>> staticAnchors,
									 std::string activeImage, BUtilities::Point<> activeAnchor,
									 std::string dynamicImage, BUtilities::Point<> dynamicAnchor,
									 double value, const double min, const double max, double step, 
									 uint32_t urid, std::string title) : 
	ImageVSlider	(0.0, 0.0, BWIDGETS_DEFAULT_IMAGEVSLIDER_WIDTH, BWIDGETS_DEFAULT_IMAGEVSLIDER_HEIGHT,
					 staticImage, staticAnchors, activeImage, activeAnchor, dynamicImage, dynamicAnchor,
					 value, min, max, step, 
					 ValueTransferable<double>::noTransfer, ValueTransferable<double>::noTransfer, 
					 urid, title) 
{

}

inline ImageVSlider::ImageVSlider	(const double  x, const double y, const double width, const double height, 
								 const std::string staticImage, const std::pair<BUtilities::Point<>, BUtilities::Point<>> staticAnchors,
								 std::string activeImage, BUtilities::Point<> activeAnchor,
								 std::string dynamicImage, BUtilities::Point<> dynamicAnchor,
								 double value, const double min, const double max, double step,
								 std::function<double (const double& x)> transferFunc,
					 			 std::function<double (const double& x)> reTransferFunc, 
								 uint32_t urid, std::string title) :
		ImageVMeter	(x, y, width, height,
					 staticImage, staticAnchors, activeImage, activeAnchor, dynamicImage, dynamicAnchor,
					 value, min, max, step, 
					 ValueTransferable<double>::noTransfer, ValueTransferable<double>::noTransfer, 
					 urid, title),
		Clickable(),
		Draggable(),
		Scrollable()
{

}

inline Widget* ImageVSlider::clone () const 
{
	Widget* f = new ImageVSlider (urid_, title_);
	f->copy (this);
	return f;
}

inline void ImageVSlider::copy (const ImageVSlider* that)
{
	Scrollable::operator= (*that);
	Draggable::operator= (*that);
	Clickable::operator= (*that);
	ImageVMeter::copy (that);
}

inline void ImageVSlider::onButtonPressed (BEvents::Event* event)
{
	BEvents::PointerEvent* pev = dynamic_cast<BEvents::PointerEvent*> (event);
	if (!pev) return;

	if (staticAnchors_.first.y != staticAnchors_.second.y)
	{
		const double x0 = getXOffset();
		const double w = getEffectiveWidth();
		const double h = getEffectiveHeight();
		const double ws = cairo_image_surface_get_width (staticImageSurface_);
		const double hs = cairo_image_surface_get_height (staticImageSurface_);
		if ((ws >= 1.0) && (hs >= 1.0) && (w >= 1) && (h >= 1))
		{
			const double szs = ((w / ws < h / hs) ? (w / ws) : (h / hs));
			const double y0s = x0 + 0.5 * h - 0.5 * hs * szs;

			if (step_ >= 0)
			{
				setValue (getValueFromRatio	((pev->getPosition().y - y0s - staticAnchors_.first.y * szs) / ((staticAnchors_.second.y - staticAnchors_.first.y) * szs)));
			}
			else
			{
				setValue (getValueFromRatio	(1.0 - (pev->getPosition().y - y0s - staticAnchors_.first.y * szs) / ((staticAnchors_.second.y - staticAnchors_.first.y) * szs)));
			}
		}
	}
	Clickable::onButtonPressed (event);
}

inline void ImageVSlider::onPointerDragged (BEvents::Event* event)
{
	if (isClickable()) onButtonPressed (event);
	else
	{
		BEvents::PointerEvent* pev = dynamic_cast<BEvents::PointerEvent*> (event);
		if (!pev) return;

		if (staticAnchors_.first.y != staticAnchors_.second.y)
		{
			const double w = getEffectiveWidth();
			const double h = getEffectiveHeight();
			const double ws = cairo_image_surface_get_width (staticImageSurface_);
			const double hs = cairo_image_surface_get_height (staticImageSurface_);
			if ((ws >= 1.0) && (hs >= 1.0) && (w >= 1) && (h >= 1))
			{
				const double szs = ((w / ws < h / hs) ? (w / ws) : (h / hs));

				if (getStep() != 0.0) setValue (getValue() - pev->getDelta().y * getStep ());
				else setValue (getValueFromRatio (getRatioFromValue (getValue()) + pev->getDelta().y / ((staticAnchors_.second.y - staticAnchors_.first.y) * szs)));
			}
		}
	}
	Draggable::onPointerDragged (event);
}

inline void ImageVSlider::onWheelScrolled (BEvents::Event* event)
{
	BEvents::WheelEvent* wev = dynamic_cast<BEvents::WheelEvent*> (event);
	if (!wev) return;

	if (staticAnchors_.first.y != staticAnchors_.second.y)
	{
		const double w = getEffectiveWidth();
		const double h = getEffectiveHeight();
		const double ws = cairo_image_surface_get_width (staticImageSurface_);
		const double hs = cairo_image_surface_get_height (staticImageSurface_);
		if ((ws >= 1.0) && (hs >= 1.0) && (w >= 1) && (h >= 1))
		{
			const double szs = ((w / ws < h / hs) ? (w / ws) : (h / hs));

			if (getStep() != 0.0) setValue (getValue() - wev->getDelta().y * getStep ());
			else setValue (getValueFromRatio (getRatioFromValue(getValue()) + wev->getDelta().y / ((staticAnchors_.second.y - staticAnchors_.first.y) * szs)));
		}
	}

	Scrollable::onWheelScrolled (event);
}

}

#endif /* BWIDGETS_IMAGEVSLIDER_HPP_ */
