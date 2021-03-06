/*
epple2
Copyright (C) 2008 by Christopher A. Mosher <cmosher01@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY, without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef CASSETTE_H
#define CASSETTE_H

#include <vector>
#include <string>
#include <cstdint>

#include "screenimage.h"

class Cassette {
    protected:
        ScreenImage& gui;

        std::uint_fast32_t t;
        std::uint_fast32_t t_active;

        bool playing; // tape is moving

        bool modified;
        std::string file;

        // save all data to file, return true if it worked
        virtual bool write() { return true; }
        virtual std::string port() { return ""; }
        void note(const char *n);

    public:
        Cassette(ScreenImage& gui);
        virtual ~Cassette();

        virtual bool eject(); // returns false if user cancels operation
        void save();

        bool isLoaded();
        bool isModified();

        virtual void tick();
};

#endif
