/* ImageDial.hpp
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

#ifndef BWIDGETS_IMAGEDIAL_HPP_
#define BWIDGETS_IMAGEDIAL_HPP_

#include "ImageRadialMeter.hpp"
#include "Supports/Clickable.hpp"
#include "Supports/Draggable.hpp"
#include "Supports/Scrollable.hpp"
#include "../BEvents/WheelEvent.hpp"

#ifndef BWIDGETS_DEFAULT_IMAGEDIAL_WIDTH
#define BWIDGETS_DEFAULT_IMAGEDIAL_WIDTH BWIDGETS_DEFAULT_IMAGERADIALMETER_WIDTH
#endif

#ifndef BWIDGETS_DEFAULT_IMAGEDIAL_HEIGHT
#define BWIDGETS_DEFAULT_IMAGEDIAL_HEIGHT BWIDGETS_DEFAULT_IMAGERADIALMETER_HEIGHT
#endif

namespace BWidgets
{

/**
 *  @brief  %ImageDial widget.
 *
 *  %ImageDial is a Valueable widget derived from ImageRadialMeter. It displays 
 *  a value in a radial representation in the same way as ImageRadialMeter and 
 *  additionally supports user interaction via Clickable, Draggable, and 
 *  Scrollable.
 */
class ImageDial :	public ImageRadialMeter, 
					public Clickable, 
					public Draggable, 
					public Scrollable
{
public:

	/**
	 * @brief  Constructs an empty %ImageDial object.
	 * 
	 */
	ImageDial ();

	/**
	 *  @brief  Constructs an empty %ImageDial object.
	 *  @param URID  URID.
	 *  @param title  %Widget title.
	 */
	ImageDial (const uint32_t urid, const std::string& title);

	/**
	 *  @brief  Creates a %ImageDial with default size.
	 *  @param staticImage  Filename of the static passive content image.
	 *  @param staticAnchor  Anchor point of the static active content which 
	 *  also represents the center of rotation
	 *  @param staticMinAngle  Angle for the min value.
	 *  @param staticMaxAngle  Angle for the max value.
	 *  @param activeImage  Optional, filename of the static active content 
	 *  image.
	 *  @param activeAnchor  Optional, anchor point of the static active
	 *  content which fits to center of rotation.
	 *  @param dynamicImage  Optional, filename of the dynamic content image.
	 *  @param dynamicAnchor  Optional, anchor point of the dynamic content
	 *  which fits to center of rotation.
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
	ImageDial	(const std::string staticImage, const BUtilities::Point<> staticAnchor, const double staticMinAngle, const double staticMaxAngle,
				 std::string activeImage = "", BUtilities::Point<> activeAnchor = {0,0},
				 std::string dynamicImage = "", BUtilities::Point<> dynamicAnchor = {0,0},
				 double value = 0.0, double min = 0.0, double max = 1.0, double step = 0.0, 
				 uint32_t urid = URID_UNKNOWN_URID, std::string title = "");

	/**
	 *  @brief  Creates a %ImageDial.
	 *  @param x  %ImageDial X origin coordinate.
	 *  @param y  %ImageDial Y origin coordinate.
	 *  @param width  %ImageDial width.
	 *  @param height  %ImageDial height.
	 *  @param staticImage  Filename of the static passive content image.
	 *  @param staticAnchor  Anchor point of the static active content which 
	 *  also represents the center of rotation
	 *  @param staticMinAngle  Angle for the min value.
	 *  @param staticMaxAngle  Angle for the max value.
	 *  @param activeImage  Optional, filename of the static active content 
	 *  image.
	 *  @param activeAnchor  Optional, anchor point of the static active
	 *  content which fits to center of rotation.
	 *  @param dynamicImage  Optional, filename of the dynamic content image.
	 *  @param dynamicAnchor  Optional, anchor point of the dynamic content
	 *  which fits to center of rotation.
	 *  @param value  Optional, initial value.
	 *  @param min  Optional, lower value limit.
	 *  @param max  Optional, upper value limit.
	 *  @param step  Optional, value increment steps.
	 *  @param transferFunc  Optinonal, function to transfer a value from an
	 *  external context to the internal context.
	 *  @param reTransferFunc  Optinonal, function to transfer a value from the
	 *  internal context to an external context.
	 *  @param urid  Optional, URID (default = URID_UNKNOWN_URID).
	 *  @param title  Optional, %ImageDial title (default = "").
	 *
	 *  Note: It's mandatory to provide an image for the static passive content
	 *  @a staticImage (background, labels, ...) and its anchor points for the
	 *  min value and the max value. The image area of @a staticImage MUST
	 *  cover ALL possible positions of the static active content 
	 *  @a activeImage and the dynamic content @a dynamicImage.
	 */
	ImageDial	(const double x, const double y, const double width, const double height, 
				 const std::string staticImage, const BUtilities::Point<> staticAnchor, const double staticMinAngle, const double staticMaxAngle,
				 std::string activeImage = "", BUtilities::Point<> activeAnchor = {0,0},
				 std::string dynamicImage = "", BUtilities::Point<> dynamicAnchor = {0,0},
				 double value = 0.0, double min = 0.0, double max = 1.0, double step = 0.0, 
				 std::function<double (const double& x)> transferFunc = ValueTransferable<double>::noTransfer,
				 std::function<double (const double& x)> reTransferFunc = ValueTransferable<double>::noTransfer,
				 uint32_t urid = URID_UNKNOWN_URID, std::string title = "");

	/**
	 *  @brief  Creates a clone of the %ImageDial. 
	 *  @return  Pointer to the new %ImageDial.
	 *
	 *  Creates a clone of this %ImageDial by copying all properties. But NOT its
	 *  linkage.
	 *
	 *  Allocated heap memory needs to be freed using @c delete if the clone
	 *  in not needed anymore!
	 */
	virtual Widget* clone () const override; 

	/**
	 *  @brief  Copies from another %ImageDial. 
	 *  @param that  Other %ImageDial.
	 *
	 *  Copies all properties from another %ImageDial. But NOT its linkage.
	 */
	void copy (const ImageDial* that);

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

inline ImageDial::ImageDial () :
	ImageDial	(0.0, 0.0, BWIDGETS_DEFAULT_IMAGERADIALMETER_WIDTH, BWIDGETS_DEFAULT_IMAGERADIALMETER_HEIGHT,
				 "", BUtilities::Point<>(0,0), 0.0, 2.0 * M_PI,
				 "", BUtilities::Point<> (0,0),
				 "", BUtilities::Point<> (0,0),
				 0.0, 0.0, 1.0, 0.0, 
				 ValueTransferable<double>::noTransfer, ValueTransferable<double>::noTransfer, 
				 URID_UNKNOWN_URID, "")
{

}

inline ImageDial::ImageDial (const uint32_t urid, const std::string& title) : 
	ImageDial	(0.0, 0.0, BWIDGETS_DEFAULT_IMAGERADIALMETER_WIDTH, BWIDGETS_DEFAULT_IMAGERADIALMETER_HEIGHT,
				 "", BUtilities::Point<>(0,0), 0.0, 2.0 * M_PI,
				 "", BUtilities::Point<> (0,0),
				 "", BUtilities::Point<> (0,0),
				 0.0, 0.0, 1.0, 0.0, 
				 ValueTransferable<double>::noTransfer, ValueTransferable<double>::noTransfer, 
				 urid, title)
{

}

inline ImageDial::ImageDial (const std::string staticImage, const BUtilities::Point<> staticAnchor, 
							 const double staticMinAngle, const double staticMaxAngle,
							 std::string activeImage, BUtilities::Point<> activeAnchor,
							 std::string dynamicImage, BUtilities::Point<> dynamicAnchor,
							 double value, const double min, const double max, double step, 
							 uint32_t urid, std::string title) : 
	ImageDial	(0.0, 0.0, BWIDGETS_DEFAULT_IMAGERADIALMETER_WIDTH, BWIDGETS_DEFAULT_IMAGERADIALMETER_HEIGHT,
						 staticImage, staticAnchor, staticMinAngle, staticMaxAngle, 
						 activeImage, activeAnchor, dynamicImage, dynamicAnchor,
						 value, min, max, step, 
						 ValueTransferable<double>::noTransfer, ValueTransferable<double>::noTransfer, 
						 urid, title) 
{

}

inline ImageDial::ImageDial	(const double  x, const double y, const double width, const double height, 
							 const std::string staticImage, const BUtilities::Point<> staticAnchor, 
							 const double staticMinAngle, const double staticMaxAngle,
							 std::string activeImage, BUtilities::Point<> activeAnchor,
							 std::string dynamicImage, BUtilities::Point<> dynamicAnchor,
							 double value, const double min, const double max, double step,
							 std::function<double (const double& x)> transferFunc,
				 			 std::function<double (const double& x)> reTransferFunc, 
							 uint32_t urid, std::string title) :
		ImageRadialMeter	(x, y, width, height,
					 staticImage, staticAnchor, staticMinAngle, staticMaxAngle, activeImage, activeAnchor, dynamicImage, dynamicAnchor,
					 value, min, max, step, 
					 ValueTransferable<double>::noTransfer, ValueTransferable<double>::noTransfer, 
					 urid, title),
		Clickable(),
		Draggable(),
		Scrollable()
{
}

inline Widget* ImageDial::clone () const 
{
	Widget* f = new ImageDial (urid_, title_);
	f->copy (this);
	return f;
}

inline void ImageDial::copy (const ImageDial* that)
{
	Scrollable::operator= (*that);
	Draggable::operator= (*that);
	Clickable::operator= (*that);
	ImageRadialMeter::copy (that);
}

inline void ImageDial::onButtonPressed (BEvents::Event* event)
{
	BEvents::PointerEvent* pev = dynamic_cast<BEvents::PointerEvent*> (event);
	if (!pev) return;

	if (staticMinAngle_ != staticMaxAngle_)
	{
		const double x0 = getXOffset();
		const double y0 = getYOffset();
		const double w = getEffectiveWidth();
		const double h = getEffectiveHeight();
		const double ws = cairo_image_surface_get_width (staticImageSurface_);
		const double hs = cairo_image_surface_get_height (staticImageSurface_);

		if ((ws >= 1.0) && (hs >= 1.0) && (w >= 1) && (h >= 1))
		{
			const double szs = ((w / ws < h / hs) ? (w / ws) : (h / hs));
			const double xc = x0 + 0.5 * w - 0.5 * ws * szs + staticAnchor_.x * szs;
			const double yc = y0 + 0.5 * h - 0.5 * hs * szs + staticAnchor_.y * szs;
			const double r = sqrt (pow (pev->getPosition().x - xc, 2.0) + pow (pev->getPosition().y - yc, 2.0));
			if (r >= 1.0)
			{
				double a = (pev->getPosition().y  < yc ? 2.0 * M_PI - acos ((pev->getPosition().x - xc) / r) : acos ((pev->getPosition().x - xc) / r));
				if (a < staticMinAngle_) a += 2.0 * M_PI;
				if (a > staticMaxAngle_) a -= 2.0 * M_PI;
				if ((a >= staticMinAngle_) && (a <= staticMaxAngle_)) 
				{
					if (step_ < 0.0) a = staticMaxAngle_ - (a - staticMinAngle_);
					setValue (getValueFromRatio	((a - staticMinAngle_) / (staticMaxAngle_ - staticMinAngle_)));
				}
			}
		}
	}
	Clickable::onButtonPressed (event);
}

inline void ImageDial::onPointerDragged (BEvents::Event* event)
{
	if (isClickable()) onButtonPressed (event);
	else
	{
		BEvents::PointerEvent* pev = dynamic_cast<BEvents::PointerEvent*> (event);
		if (!pev) return;

		const double w = getEffectiveWidth();
		const double h = getEffectiveHeight();
		const double r = 0.5 * std::min (w, h);

		if ((staticMinAngle_ != staticMaxAngle_) && (r >= 1.0))
		{
			if (getStep() != 0.0) setValue (getValue() - pev->getDelta().y * getStep ());
			else setValue (getValueFromRatio (getRatioFromValue(getValue()) - pev->getDelta().y / ((staticMaxAngle_ - staticMinAngle_) * r)));
		}
	}
	Draggable::onPointerDragged (event);
}

inline void ImageDial::onWheelScrolled (BEvents::Event* event)
{
	BEvents::WheelEvent* wev = dynamic_cast<BEvents::WheelEvent*> (event);
	if (!wev) return;

	const double w = getEffectiveWidth();
		const double h = getEffectiveHeight();
		const double r = 0.5 * std::min (w, h);

		if ((staticMinAngle_ != staticMaxAngle_) && (r >= 1.0))
	{
		if (getStep() != 0.0) setValue (getValue() - wev->getDelta().y * getStep ());
		else setValue (getValueFromRatio (getRatioFromValue(getValue()) - wev->getDelta().y / ((staticMaxAngle_ - staticMinAngle_) * r)));
	}

	Scrollable::onWheelScrolled (event);
}

}

#endif /* BWIDGETS_IMAGEDIAL_HPP_ */
