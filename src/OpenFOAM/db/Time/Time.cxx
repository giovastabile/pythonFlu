//  VulaSHAKA (Simultaneous Neutronic, Fuel Performance, Heat And Kinetics Analysis)
//  Copyright (C) 2009-2010 Pebble Bed Modular Reactor (Pty) Limited (PBMR)
//  
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//  See https://vulashaka.svn.sourceforge.net/svnroot/vulashaka/pyfoam
//
//  Author : Alexey PETROV


//---------------------------------------------------------------------------
#ifndef Time_cxx
#define Time_cxx


//---------------------------------------------------------------------------
%include "src/OpenFOAM/db/objectRegistry.cxx"

%include "src/OpenFOAM/db/Time/clock.cxx"

%include "src/OpenFOAM/db/Time/cpuTime.cxx"

%include "src/OpenFOAM/db/Time/TimePaths.cxx"

%include "src/OpenFOAM/db/Time/TimeState.cxx"

%include "src/OpenFOAM/primitives/scalar.cxx"

%include "src/OpenFOAM/dimensionedTypes/dimensionedScalar.cxx"

%include "src/OpenFOAM/primitives/strings/word.cxx"

%ignore Foam::Time::writeVersion;

%{
    #include "Time.H"
%}

%include "Time.H"

%extend Foam::Time
{
    void step()
    {
        self->operator++();
    }
}


//---------------------------------------------------------------------------
#endif
