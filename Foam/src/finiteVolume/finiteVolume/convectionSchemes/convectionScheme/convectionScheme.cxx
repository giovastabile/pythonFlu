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
//  See https://vulashaka.svn.sourceforge.net/svnroot/vulashaka
//
//  Author : Alexey PETROV


//---------------------------------------------------------------------------
#ifndef convectionScheme_cxx
#define convectionScheme_cxx


//---------------------------------------------------------------------------
%module "Foam.src.finiteVolume.finiteVolume.convectionSchemes.convectionScheme.convectionScheme";
%{
  #include "src/finiteVolume/finiteVolume/convectionSchemes/convectionScheme/convectionScheme.hh"
%}


//---------------------------------------------------------------------------
%import "src/OpenFOAM/fields/tmp/tmp.cxx"

%import "src/OpenFOAM/fields/tmp/refCount.cxx"

%import "src/finiteVolume/fvMesh/fvMeshes.cxx"

%import "src/OpenFOAM/db/typeInfo/typeInfo.hxx"

%import "src/finiteVolume/interpolation/surfaceInterpolation/multivariateSchemes/multivariateSurfaceInterpolationScheme/multivariateSurfaceInterpolationScheme.cxx"

%include <convectionScheme.H>


//---------------------------------------------------------------------------
#endif