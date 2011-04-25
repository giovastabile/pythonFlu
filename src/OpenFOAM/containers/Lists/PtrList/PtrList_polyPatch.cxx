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
#ifndef PtrList_polyPatch_cxx
#define PtrList_polyPatch_cxx


//---------------------------------------------------------------------------
%module "Foam.src.OpenFOAM.containers.Lists.PtrList.PtrList_polyPatch";
%{
   #include "src/OpenFOAM/containers/Lists/PtrList/PtrList_polyPatch.hh"
%}


//---------------------------------------------------------------------------
%import "src/OpenFOAM/meshes/polyMesh/polyPatches/polyPatch.cxx"

%import "src/OpenFOAM/containers/Lists/PtrList/PtrList.cxx"

%ignore Foam::PtrList< Foam::polyPatch >::PtrList;
%ignore Foam::PtrList< Foam::polyPatch >::begin;
%ignore Foam::PtrList< Foam::polyPatch >::end;
%ignore Foam::PtrList< Foam::polyPatch >::set;

#if FOAM_VERSION( >=, 010600 )
  %ignore Foam::PtrList< Foam::polyPatch >::xfer;
#endif

%template (polyPatchList) Foam::PtrList< Foam::polyPatch >;

%extend Foam::PtrList< Foam::polyPatch > PTRLISTBASED_ADDONS( Foam::polyPatch )

%include <polyPatchList.H>


//---------------------------------------------------------------------------
#endif
