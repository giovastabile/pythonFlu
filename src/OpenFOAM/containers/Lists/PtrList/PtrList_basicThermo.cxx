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
//  See https://csrcs.pbmr.co.za/svn/nea/prototypes/reaktor/pyfoam
//
//  Author : Alexey PETROV


//---------------------------------------------------------------------------
#ifndef PtrList_basicThermo_cxx
#define PtrList_basicThermo_cxx


//---------------------------------------------------------------------------
// Keep on corresponding "director" includes at the top of SWIG defintion file

%include "src/OpenFOAM/directors.hxx"

%include "src/finiteVolume/directors.hxx"


//---------------------------------------------------------------------------
%include "src/thermophysicalModels/basic/basicThermo.cxx"

%include "src/OpenFOAM/fields/tmp/autoPtr_basicThermo.cxx"

%include "src/OpenFOAM/containers/Lists/PtrList/PtrList.cxx"

%ignore Foam::PtrList< Foam::basicThermo >::PtrList;
%ignore Foam::PtrList< Foam::basicThermo >::begin;
%ignore Foam::PtrList< Foam::basicThermo >::end;
%ignore Foam::PtrList< Foam::basicThermo >::set;

#if ( __FOAM_VERSION__ >= 010600 )
%ignore Foam::PtrList< Foam::basicThermo >::xfer;
#endif

%template( PtrList_basicThermo ) Foam::PtrList< Foam::basicThermo >;


//---------------------------------------------------------------------------
%extend Foam::PtrList< Foam::basicThermo >
{
  Foam::PtrList< Foam::basicThermo >( const Foam::label s )
  {
    return new Foam::PtrList< Foam::basicThermo >( s );
  }
}

%extend Foam::PtrList< Foam::basicThermo > PTRLISTBASED_ADDONS( Foam::basicThermo )


//---------------------------------------------------------------------------
#endif