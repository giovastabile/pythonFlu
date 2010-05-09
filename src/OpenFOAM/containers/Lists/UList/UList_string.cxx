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
#ifndef UList_string_cxx
#define UList_string_cxx


//---------------------------------------------------------------------------
%include "src/OpenFOAM/containers/Lists/UList/UList.cxx"

%include "src/OpenFOAM/primitives/strings/string.cxx"

%ignore Foam::UList< Foam::string >::writeEntry;

%template( UList_string ) Foam::UList< Foam::string >; 

%extend Foam::UList< Foam::string > SEQUENCE_ADDONS( Foam::string )

%extend Foam::UList< Foam::string >
{
  #if ( __FOAM_VERSION__ >= 010600 ) 

    Foam::label ext_findIndex( const Foam::string& t, const label start=0 )
    {
       return Foam::findIndex( *self, t, start );
    }

  #endif

  #if ( __FOAM_VERSION__ < 010600 )

    Foam::label ext_findIndex( const Foam::string& t )
    {
     return Foam::findIndex( *self, t );
    }

  #endif
}


//---------------------------------------------------------------------------
#endif
