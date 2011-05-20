//  pythonFlu - Python wrapping for OpenFOAM C++ API
//  Copyright (C) 2010- Alexey Petrov
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
//  See https://vulashaka.svn.sourceforge.net/svnroot/vulashaka
//
//  Author : Alexey PETROV


//---------------------------------------------------------------------------
#ifndef surfaceInterpolation_cpp
#define surfaceInterpolation_cpp


//---------------------------------------------------------------------------
%module "Foam.src.finiteVolume.interpolation.surfaceInterpolation.surfaceInterpolation";
%{
  #include "src/finiteVolume/interpolation/surfaceInterpolation/surfaceInterpolation.hh"
%}


//---------------------------------------------------------------------------
%import "src/OpenFOAM/fields/tmp/tmp.cxx"

%import "src/OpenFOAM/primitives/scalar.cxx"
%import "src/finiteVolume/finiteVolume/fvSchemes.cxx"
%import "src/finiteVolume/finiteVolume/fvSolution.cxx"

%include "src/finiteVolume/fields/volFields/volFieldsFwd.hpp"
%include "src/finiteVolume/fields/surfaceFields/surfaceFieldsFwd.hpp"

%include <surfaceInterpolation.H>


//---------------------------------------------------------------------------
#endif
