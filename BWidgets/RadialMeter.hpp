/* RadialMeter.hpp
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

#ifndef BWIDGETS_RADIALMETER_HPP_
#define BWIDGETS_RADIALMETER_HPP_

#ifndef BWIDGETS_DEFAULT_DRAWRMETER_PATH
#define BWIDGETS_DEFAULT_DRAWRMETER_PATH "Draws/drawRMeter.hpp"
#endif

#include "Widget.hpp"
#include "Label.hpp"
#include "Supports/Validatable.hpp"
#include "Supports/ValueableTyped.hpp"
#include "Supports/ValidatableRange.hpp"
#include "Supports/ValueTransferable.hpp"
#include BWIDGETS_DEFAULT_DRAWRMETER_PATH
#include <cairo/cairo.h>
#include <cmath>

#ifndef BWIDGETS_DEFAULT_RADIALMETER_WIDTH
#define BWIDGETS_DEFAULT_RADIALMETER_WIDTH 40.0
#endif

#ifndef BWIDGETS_DEFAULT_RADIALMETER_HEIGHT
#define BWIDGETS_DEFAULT_RADIALMETER_HEIGHT 40.0
#endif

#ifndef STYLEPROPERTY_HICOLORS_URI
#define STYLEPROPERTY_HICOLORS_URI STYLEPROPERTY_URI "#HiColors"
#endif

namespace BWidgets
{

/**
 *  @brief  %RadialMeter widget.
 *
 *  %RadialMeter is a Valueable Widget and displays a value as a radial
 *  meter without user interaction. The value is kept within a defined range
 *  and displayed in blocks defined by the parameter @a step . Its appearance
 *  is defined by the parameters BgColors (static elements), FgColors (value,
 *  low range), and HiColors (value, high range).
 *
 *  Advanced settings allow a %RadialMeter to display a value in a non-linear
 *  manner (e.g. for levels and frequencies) using transfer functions and / or
 *  to use non-line color gradients for display using gradient functions.
 */
class RadialMeter :	public Widget, 
				public ValueableTyped<double>, 
				public ValidatableRange<double>, 
				public ValueTransferable<double>
{
protected:
	BUtilities::Area<> scale_;
	std::function<double (const double& x)> gradient_ = noTransfer;

public:

	/**
	 *  @brief  Constructs a default %RadialMeter object.
	 */
	RadialMeter ();

	/**
	 *  @brief  Constructs a default %RadialMeter object.
	 *  @param URID  URID.
	 *  @param title  %Widget title.
	 */
	RadialMeter (const uint32_t urid, const std::string& title);

	/**
	 *  @brief  Creates a %RadialMeter with default size.
	 *  @param value  Initial value.
	 *  @param min  Lower value limit.
	 *  @param max  Upper value limit.
	 *  @param step  Optional, value increment steps.
	 *  @param urid  Optional, URID (default = URID_UNKNOWN_URID).
	 *  @param title  Optional, %Widget title (default = "").
	 */
	RadialMeter	(const double value, const double min, const double max, double step = 0.0, 
			 uint32_t urid = URID_UNKNOWN_URID, std::string title = "");

	/**
	 *  @brief  Creates a %RadialMeter.
	 *  @param x  %RadialMeter X origin coordinate.
	 *  @param y  %RadialMeter Y origin coordinate.
	 *  @param width  %RadialMeter width.
	 *  @param height  %RadialMeter height.
	 *  @param value  Initial value.
	 *  @param min  Lower value limit.
	 *  @param max  Upper value limit.
	 *  @param step  Optional, value increment steps.
	 *  @param transferFunc  Optinonal, function to transfer a value from an
	 *  external context to the internal context.
	 *  @param reTransferFunc  Optinonal, function to transfer a value from the
	 *  internal context to an external context.
	 *  @param urid  Optional, URID (default = URID_UNKNOWN_URID).
	 *  @param title  Optional, %RadialMeter title (default = "").
	 */
	RadialMeter	(const double x, const double y, const double width, const double height, 
			 const double value, const double min, const double max, double step = 0.0,
			 std::function<double (const double& x)> transferFunc = ValueTransferable<double>::noTransfer,
			 std::function<double (const double& x)> reTransferFunc = ValueTransferable<double>::noTransfer,
			 uint32_t urid = URID_UNKNOWN_URID, std::string title = "");

	/**
	 *  @brief  Creates a clone of the %RadialMeter. 
	 *  @return  Pointer to the new %RadialMeter.
	 *
	 *  Creates a clone of this %RadialMeter by copying all properties. But NOT its
	 *  linkage.
	 *
	 *  Allocated heap memory needs to be freed using @c delete if the clone
	 *  in not needed anymore!
	 */
	virtual Widget* clone () const override; 

	/**
	 *  @brief  Copies from another %RadialMeter. 
	 *  @param that  Other %RadialMeter.
	 *
	 *  Copies all properties from another %RadialMeter. But NOT its linkage.
	 */
	void copy (const RadialMeter* that);
	
	/**
     *  @brief  Optimizes the widget extends.
     *
	 *  Resizes the widget to include all direct children into the widget
	 *  area. Resizes the widget to its standard size if this widget doesn't 
	 *  have any children.
	 */
	virtual void resize () override;

    /**
     *  @brief  Resizes the widget extends.
	 *  @param width  New widget width.
	 *  @param height  New widget height.
	 */
	virtual void resize (const double width, const double height) override;

    /**
	 *  @brief  Resizes the widget extends.
	 *  @param extends  New widget extends.
	 */
	virtual void resize (const BUtilities::Point<> extends) override;

	/**
     *  @brief  Method to be called following an object state change.
     */
    virtual void update () override;

	/**
     *  @brief  Gets the high range value colors Property from the base level.
     *  @return  High range value ColorMap.
     *
     *  Gets the base level high range value colors Property using the default 
     *  high range value colors URID. Returns FgColors if the default high 
	 *  range value  colors URID is not set.
     */
    BStyles::ColorMap getHiColors() const;

    /**
     *  @brief  Sets the high range value colors Property from the base level.
     *  @param colors  High range value ColorMap.
     *
     *  Sets the base level high range value colors Property using the default 
     *  high range value colors URID.
     */
    void setHiColors (const BStyles::ColorMap& colors);

	/**
	 *  @brief  Set the color gradient function.
	 *  @param gradientFunc  Color gradient function.
	 *
	 *  The color gradient function is responsible for the (optional) color 
	 *  transition from FgColors to HiColors (if defined). By default, the
	 *  gradient is a linear function ([] (const double& x) {return x;}).
	 */
	void setGradientFunction (std::function<double (const double& x)> gradientFunc)
	{
		gradient_ = gradientFunc;
	}

protected:
	/**
     *  @brief  Unclipped draw a %RadialMeter to the surface.
     */
    virtual void draw () override;

    /**
     *  @brief  Clipped draw a %RadialMeter to the surface.
     *  @param x0  X origin of the clipped area. 
     *  @param y0  Y origin of the clipped area. 
     *  @param width  Width of the clipped area.
     *  @param height  Height of the clipped area. 
     */
    virtual void draw (const double x0, const double y0, const double width, const double height) override;

    /**
     *  @brief  Clipped draw a %RadialMeter to the surface.
     *  @param area  Clipped area. 
     */
    virtual void draw (const BUtilities::Area<>& area) override;
};

inline RadialMeter::RadialMeter () :
	RadialMeter	(0.0, 0.0, BWIDGETS_DEFAULT_RADIALMETER_WIDTH, BWIDGETS_DEFAULT_RADIALMETER_HEIGHT, 
				 0.0, 0.0, 1.0, 0.0, 
				 ValueTransferable<double>::noTransfer, ValueTransferable<double>::noTransfer, 
				 URID_UNKNOWN_URID, "")
{

}

inline RadialMeter::RadialMeter (const uint32_t urid, const std::string& title) : 
	RadialMeter	(0.0, 0.0, BWIDGETS_DEFAULT_RADIALMETER_WIDTH, BWIDGETS_DEFAULT_RADIALMETER_HEIGHT, 
				 0.0, 0.0, 1.0, 0.0, 
				 ValueTransferable<double>::noTransfer, ValueTransferable<double>::noTransfer, 
				 urid, title) 
{

}

inline RadialMeter::RadialMeter (double value, const double min, const double max, double step, uint32_t urid, std::string title) : 
	RadialMeter	(0.0, 0.0, BWIDGETS_DEFAULT_RADIALMETER_WIDTH, BWIDGETS_DEFAULT_RADIALMETER_HEIGHT, 
				 value, min, max, step, 
				 ValueTransferable<double>::noTransfer, ValueTransferable<double>::noTransfer, 
				 urid, title) 
{

}

inline RadialMeter::RadialMeter	(const double  x, const double y, const double width, const double height, 
								 double value, const double min, const double max, double step, 
								 std::function<double (const double& x)> transferFunc,
			 					 std::function<double (const double& x)> reTransferFunc,
								 uint32_t urid, std::string title) :
	Widget (x, y, width, height, urid, title),
	ValueableTyped<double> (value),
	ValidatableRange<double> (min, max, step),
	ValueTransferable<double> (transferFunc, reTransferFunc),
	scale_ (0, 0, width, height)
{
}

inline Widget* RadialMeter::clone () const 
{
	Widget* f = new RadialMeter (urid_, title_);
	f->copy (this);
	return f;
}

inline void RadialMeter::copy (const RadialMeter* that)
{
	scale_ = that->scale_;
	gradient_ = that->gradient_;
	ValueTransferable<double>::operator= (*that);
	ValidatableRange<double>::operator= (*that);
	ValueableTyped<double>::operator= (*that);
	Widget::copy (that);
}

inline void RadialMeter::resize ()
{
	BUtilities::Area<> a = (children_.empty()? BUtilities::Area<>(0, 0, BWIDGETS_DEFAULT_RADIALMETER_WIDTH, BWIDGETS_DEFAULT_RADIALMETER_HEIGHT) : BUtilities::Area<>());
	for (Linkable* c : children_)
	{
		Widget* w = dynamic_cast<Widget*>(c);
		if (w) a.extend (BUtilities::Area<>(w->getPosition(), w->getPosition() + w->getExtends()));
	}

	resize (a.getExtends());
}

inline void RadialMeter::resize (const double width, const double height) 
{
	resize (BUtilities::Point<> (width, height));
}

inline void RadialMeter::resize (const BUtilities::Point<> extends) 
{
	Widget::resize (extends);
}

inline void RadialMeter::update ()
{
	Label* f = dynamic_cast<Label*>(focus_);
	if (f)
	{
		f->setText(getTitle() + ": " + std::to_string (this->getValue()));
		f->resize();
	}

	scale_ = BUtilities::Area<> (getXOffset(), getYOffset(), getEffectiveWidth(), getEffectiveHeight());
	Widget::update();
}

inline BStyles::ColorMap RadialMeter::getHiColors() const
{
    BStyles::Style::const_iterator it = style_.find (BUtilities::Urid::urid (STYLEPROPERTY_HICOLORS_URI));
    if ((it == style_.end()) || style_.isStyle (it)) return getFgColors();
    else return it->second.get<BStyles::ColorMap>();
}

inline void RadialMeter::setHiColors (const BStyles::ColorMap& colors)
{
    style_[BUtilities::Urid::urid (STYLEPROPERTY_HICOLORS_URI)] = BUtilities::makeAny<BStyles::ColorMap> (colors);
}

inline void RadialMeter::draw ()
{
	draw (0, 0, getWidth(), getHeight());
}

inline void RadialMeter::draw (const double x0, const double y0, const double width, const double height)
{
	draw (BUtilities::Area<> (x0, y0, width, height));
}

inline void RadialMeter::draw (const BUtilities::Area<>& area)
{
	if ((!surface_) || (cairo_surface_status (surface_) != CAIRO_STATUS_SUCCESS)) return;

	// Draw super class widget elements first
	Widget::draw (area);

	// Draw only if minimum requirements satisfied
	if ((getHeight () >= 1) && (getWidth () >= 1) && (getMin() < getMax()))
	{
		cairo_t* cr = cairo_create (surface_);

		if (cairo_status (cr) == CAIRO_STATUS_SUCCESS)
		{
			// Limit cairo-drawing area
			cairo_rectangle (cr, area.getX (), area.getY (), area.getWidth (), area.getHeight ());
			cairo_clip (cr);

			const double rad = 0.5 * (scale_.getWidth() < scale_.getHeight() ? scale_.getWidth() : scale_.getHeight());
			const double rval = getRatioFromValue (getValue());
			const double drv = (std::fabs (getStep()) > 1.0 / (1.5 * M_PI * rad) ? fabs (getStep() / (getMax() - getMin())) : 1.0 / (1.5 * M_PI * rad));

			if (step_ >= 0.0)
			{
				drawRMeter	(cr, 0.5 * scale_.getWidth(), 0.5 * scale_.getHeight(), rad, 0.0, rval, drv, 
								 getFgColors()[getStatus()], getHiColors()[getStatus()], gradient_, getBgColors()[getStatus()]);
			}

			else 
			{
				drawRMeter	(cr, 0.5 * scale_.getWidth(), 0.5 * scale_.getHeight(), rad, 1.0 - rval, 1.0, drv, 
								 getFgColors()[getStatus()], getHiColors()[getStatus()], gradient_, getBgColors()[getStatus()]);
			}
		}

		cairo_destroy (cr);
	}
}

}

#endif /* BWIDGETS_RADIALMETER_HPP_ */
