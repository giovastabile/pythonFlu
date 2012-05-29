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
//  See http://sourceforge.net/projects/pythonflu
//
//  Author : Alexey PETROV


//---------------------------------------------------------------------------
#ifndef UList_sphericalTensor_cxx
#define UList_sphericalTensor_cxx


//---------------------------------------------------------------------------
%module "Foam.src.OpenFOAM.containers.Lists.UList.UList_sphericalTensor";
%{
   #include "Foam/src/OpenFOAM/containers/Lists/UList/UList_sphericalTensor.hh"
%}


//---------------------------------------------------------------------------
%import "Foam/src/OpenFOAM/containers/Lists/UList/UList.cxx"

%import "Foam/src/OpenFOAM/primitives/sphericalTensor.cxx"

#if FOAM_VERSION( <, 010500 )

%ignore Foam::UList< Foam::sphericalTensor >::operator<;
%ignore Foam::UList< Foam::sphericalTensor >::operator>;
%ignore Foam::UList< Foam::sphericalTensor >::operator>=;
%ignore Foam::UList< Foam::sphericalTensor >::operator<=;

#endif

#if SWIG_VERSION >= 0x020000 && SWIG_VERSION < 0x020003
%ignore Foam::UList< Foam::sphericalTensor >::null;
#endif


TEMPLATE_ULIST_ITERATOR( sphericalTensor );

%template( UList_sphericalTensor ) Foam::UList< Foam::sphericalTensor >;

%extend Foam::UList< Foam::sphericalTensor >
{
  ULISTBASED_ADDONS( Foam::sphericalTensor );
}


//---------------------------------------------------------------------------
#endif
