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
#ifndef multivariateSurfaceInterpolationScheme_TfieldTable_hxx
#define multivariateSurfaceInterpolationScheme_TfieldTable_hxx

//---------------------------------------------------------------------------
%include "src/nestedClass_extend.hxx"
%include "src/OpenFOAM/fields/GeometricFields/GeometricField.cxx"

%inline
{
namespace Foam
{
  //This struct redirect all call's to "nested" class multivariateSurfaceInterpolationScheme::fieldTable
  template< class Type > 
  struct TfieldTable
  {
    public:
       typedef typename multivariateSurfaceInterpolationScheme< Type >::fieldTable TSelf;
    
    private:
       TSelf engine;
    
    public:
       TfieldTable(): engine()
       {}
       
       void add( const GeometricField<Type, fvPatchField, volMesh>& f )
       {
         engine.add( f );
       }
       
       TSelf& get_self()
       {
         return engine;
       }
       const TSelf& get_self() const
       {
         return engine;
       }
  };
}
}


//---------------------------------------------------------------------------
#endif