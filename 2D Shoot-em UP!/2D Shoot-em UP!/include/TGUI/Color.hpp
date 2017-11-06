/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2017 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_COLOR_HPP
#define TGUI_COLOR_HPP

#include <TGUI/Config.hpp>
#include <SFML/Graphics/Color.hpp>
#include <cstdint>
#include <string>
#include <map>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Wrapper for colors
    ///
    /// The class is used for 2 purposes:
    /// - Implicit converter for parameters. A function taking a Color as parameter can be given an sf::Color, RGB values or
    ///   even a serialized string as argument.
    /// - Storing no color at all. Some colors may be optionally set and can thus remain unspecified.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API Color
    {
    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color with its alpha channel multiplied with the alpha parameter
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static Color calcColorOpacity(const Color& color, float alpha)
        {
            return {color.getRed(), color.getGreen(), color.getBlue(), static_cast<std::uint8_t>(color.getAlpha() * alpha)};
        }


    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Creates the object without a color
        ///
        /// The isSet() function will return false when the object was created using this constructor.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color() :
            m_isSet{false}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Creates the object from an sf::Color
        ///
        /// @param color  Color to set
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color(const sf::Color& color) :
            m_isSet{true},
            m_color{color}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Creates the object from an the RGB or RGBA values
        ///
        /// @param red   Red component
        /// @param green Green component
        /// @param blue  Blue component
        /// @param alpha Alpha component
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255) :
            m_isSet{true},
            m_color{red, green, blue, alpha}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Creates the object from a string
        ///
        /// @param string  String to be deserialized as color
        ///
        /// The Deserializer class is used to convert the string into a color.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color(const std::string& string);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Creates the object from a string
        ///
        /// @param string  String to be deserialized as color
        ///
        /// The Deserializer class is used to convert the string into a color.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color(const char* string);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Checks if a color was set
        ///
        /// @return True if a color was passed to the constructor, false when the default constructor was used
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool isSet() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Converts this object into an sf::Color object
        ///
        /// @return The color stored in this object, or the default color if no color was set
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        operator sf::Color() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the red component of the color
        ///
        /// @return Red component of the stored color or the one from the default color is no color was set
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::uint8_t getRed() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the green component of the color
        ///
        /// @return Green component of the stored color or the one from the default color is no color was set
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::uint8_t getGreen() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the blue component of the color
        ///
        /// @return Blue component of the stored color or the one from the default color is no color was set
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::uint8_t getBlue() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the alpha component of the color
        ///
        /// @return Alpha component of the stored color or the one from the default color is no color was set
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::uint8_t getAlpha() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Compares the color with another one
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool operator==(const Color& right) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Compares the color with another one
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool operator!=(const Color& right) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Compares the color with another one
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool operator==(const sf::Color& right) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Compares the color with another one
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool operator!=(const sf::Color& right) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public:

        static const Color Black;       ///< Black predefined color
        static const Color White;       ///< White predefined color
        static const Color Red;         ///< Red predefined color
        static const Color Green;       ///< Green predefined color
        static const Color Blue;        ///< Blue predefined color
        static const Color Yellow;      ///< Yellow predefined color
        static const Color Magenta;     ///< Magenta predefined color
        static const Color Cyan;        ///< Cyan predefined color
        static const Color Transparent; ///< Transparent (black) predefined color

        static const std::map<std::string, Color> colorMap;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:

        bool      m_isSet;
        sf::Color m_color;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_COLOR_HPP

