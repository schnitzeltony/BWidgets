/* Fill.hpp
 * Copyright (C) 2021  Sven Jähnichen
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

#ifndef BSTYLES_FILL_HPP_
#define BSTYLES_FILL_HPP_

#include "cairo/cairo.h"
#include "../../BUtilities/cairoplus.h"
#include "Color.hpp"
#include <string>

namespace BStyles
{

/**
 *  @brief %Fill base properties.
 *
 *  A %Fill may either be a color or an image.
 */
class Fill
{
protected:
    enum FillType
    {
        FILL_COLOR,
        FILL_IMAGE
    };

    Color color_;
    cairo_surface_t* surface_;
    FillType type_;

public:

	/**
     *  @brief  Creates an invisible %Fill.
     */
	Fill () : 
        color_ (), 
        surface_ (nullptr),
        type_ (FILL_COLOR)
    {

    }

	/**
     *  @brief  Creates a plain single color %Fill.
     *  @param color  %Fill @a color.
     */
	Fill (const Color& color) : 
        color_ (color), 
        surface_ (nullptr),
        type_ (FILL_COLOR)
    {

    }

    /**
     *  @brief  Creates an image %Fill from a Cairo surface.
     *  @param surface  Cairo image surface.
     *
     *  The constructor creates a copy of the Cairo image surface.
     */
	Fill (cairo_surface_t* surface) :
        color_ (),
        surface_    (surface && (cairo_surface_status (surface) == CAIRO_STATUS_SUCCESS) ? 
                     cairoplus_image_surface_clone_from_image_surface (surface) : 
                     nullptr),
        type_ (FILL_IMAGE)
    {
    
    }

    /**
     *  @brief  Creates an image %Fill from a png file.
     *  @param filename  png file name.
     */
	Fill (const std::string& filename) :
        color_ (),
        surface_ (cairo_image_surface_create_from_png (filename.c_str())),
        type_ (FILL_IMAGE)
    {
    
    }

    /**
     *  @brief  Copy constructs a new %Fill from another one.
     *  @param that  %Fill to copy from.
     */
    Fill (const Fill& that) :
        color_ (that.color_),
        surface_    (that.surface_ && (cairo_surface_status (that.surface_) == CAIRO_STATUS_SUCCESS) ? 
                     cairoplus_image_surface_clone_from_image_surface (that.surface_) : 
                     nullptr),
        type_ (that.type_)
    {
    
    }

    ~Fill ()
    {
        if (surface_ && (cairo_surface_status (surface_) == CAIRO_STATUS_SUCCESS)) cairo_surface_destroy (surface_);
    }

    /**
     *  @brief  Sets the %Fill by copying from another one.
     *  @param that  Source %Fill.
     *
     *  Sets the %Fill by copying from another one. Frees the 
     *  previously stored image source (if exists) first.
     */
    Fill& operator= (const Fill& that)
    {
        color_ = that.color_;
        type_ = that.type_;

        if (surface_ != that.surface_)
        {
            if (surface_ && (cairo_surface_status (surface_) == CAIRO_STATUS_SUCCESS)) cairo_surface_destroy (surface_);
            if (that.surface_) surface_ = cairoplus_image_surface_clone_from_image_surface (that.surface_);
            else surface_ = nullptr;
        }

        return *this;
    }

    bool operator== (const Fill& that) const 
    {
        return (type_ == that.type_) && (type_ == FILL_COLOR ? color_ == that.color_ : surface_ == that.surface_);
    }

	bool operator!= (const Fill& that) const {return !operator== (that);}

    /**
     *  @brief  Sets the %Fill to a Color.
     *  @param color  Color.
     *
     *  Sets the %Fill to a Color and sets the fill type to FILL_COLOR. Frees
     *  a previously stored image surface first.
     */
    void set (const Color& color)
    {
        if (surface_ && (cairo_surface_status (surface_) == CAIRO_STATUS_SUCCESS)) cairo_surface_destroy (surface_);
        surface_ = nullptr;
        color_ = color;
        type_ = FILL_COLOR;
    }

    /**
     *  @brief  Sets the %Fill by copying an image @a surface from a Cairo 
     *  surface.
     *  @param surface  Pointer to a Cairo surface.
     *
     *  Sets the %Fill by copying an image @a surface from a Cairo surface
     *  and sets the fill type to FILL_IMAGE. Frees the previously stored 
     *  image surface first.
     */
    void set (cairo_surface_t* surface)
    {
        if (surface_ != surface)
        {
            if (surface_ && (cairo_surface_status (surface_) == CAIRO_STATUS_SUCCESS)) cairo_surface_destroy (surface_);
            if (surface) surface_ = cairoplus_image_surface_clone_from_image_surface (surface);
            else surface_ = nullptr;
        }

        type_ = FILL_IMAGE;
    }

    /**
     *  @brief  Sets the %Fill to an image by loading png file.
     *  @param filename  Name / path to a png file.
     *
     *  Loads the %Fill from a png fileand sets the fill type to FILL_IMAGE. 
     *  Frees the previously stored image surface first.
     */
    void set (const std::string& filename)
    {
        if (surface_ && (cairo_surface_status (surface_) == CAIRO_STATUS_SUCCESS)) cairo_surface_destroy (surface_);
        if (filename != "") surface_ = cairo_image_surface_create_from_png (filename.c_str());
        else surface_ = nullptr;

        type_ = FILL_IMAGE;
    }

    /**
     *  @brief  Sets the %Fill souce to a Cairo context.
     *  @param cr  Cairo context.
     */
	void setCairoSource (cairo_t* cr) const
    {
        switch (type_)
        {
            case FILL_COLOR:    cairo_set_source_rgba (cr, CAIRO_RGBA (color_));
                                break;

            case FILL_IMAGE:    if (surface_) cairo_set_source_surface (cr, surface_, 0.0, 0.0);
                                break;
        };
    }
};

const Fill blackFill = Fill (black);
const Fill whiteFill = Fill (white);
const Fill redFill = Fill (red);
const Fill greenFill = Fill (green);
const Fill blueFill = Fill (blue);
const Fill greyFill = Fill (grey);
const Fill darkgreyFill = Fill (darkgrey);
const Fill grey20Fill = Fill (grey20);
const Fill noFill = Fill (invisible);
const Fill shadow80Fill = Fill (Color (0.0, 0.0, 0.0, 0.8));
const Fill shadow50Fill = Fill (Color (0.0, 0.0, 0.0, 0.5));
const Fill shadow20Fill = Fill (Color (0.0, 0.0, 0.0, 0.2));

}

#endif /* BSTYLES_FILL_HPP_ */
