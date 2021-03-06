/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 1991-2007 OpenCFD Ltd.
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Class
    DimensionedField<T>

Description
    Field with dimensions and associated with geometry type GeoMesh which is
    used to size the field and a reference to it is maintained.

SourceFiles
    DimensionedFieldI.H
    DimensionedField.C
    DimensionedFieldIO.C

\*---------------------------------------------------------------------------*/

#ifndef DimensionedField_H
#define DimensionedField_H

#include "regIOobject.H"
#include "Field.H"
#include "dimensionedType.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * Forward declaration of template friend fuctions * * * * * * * //
 
template<class Type, class GeoMesh> class DimensionedField;

template<class Type, class GeoMesh> Ostream& operator<<
(
    Ostream&,
    const DimensionedField<Type, GeoMesh>&
);

template<class Type, class GeoMesh> Ostream& operator<<
(
    Ostream&,
    const tmp<DimensionedField<Type, GeoMesh> >&
);


/*---------------------------------------------------------------------------*\
                           Class DimensionedField Declaration
\*---------------------------------------------------------------------------*/

template<class Type, class GeoMesh>
class DimensionedField
:
    public regIOobject,
    public Field<Type>
{

public:

    // Public typedefs

        typedef typename GeoMesh::Mesh Mesh;
        typedef typename Field<Type>::cmptType cmptType;


private:

    // Private data

        //- Reference to mesh
        const Mesh& mesh_;

        //- Dimension set for this field
        dimensionSet dimensions_;


public:

    //- Runtime type information
    TypeName("DimensionedField");


    // Constructors

        //- Construct from components
        DimensionedField
        (
            const IOobject&,
            const Mesh& mesh,
            const dimensionSet&,
            const Field<Type>&
        );

        //- Construct from components
        //  Used for temporary fields which are initialised after construction
        DimensionedField
        (
            const IOobject&,
            const Mesh& mesh,
            const dimensionSet&
        );

        //- Construct from components
        DimensionedField
        (
            const IOobject&,
            const Mesh& mesh,
            const dimensioned<Type>&
        );

        //- Construct from Istream
        DimensionedField
        (
            const IOobject&,
            const Mesh& mesh,
            const word& fieldDictEntry="value"
        );

        void readField
        (
            const dictionary& fieldDict,
            const word& fieldDictEntry="value"
        );

        //- Construct as copy
        DimensionedField
        (
            const DimensionedField<Type, GeoMesh>&
        );

        //- Construct as copy or re-use as specified.
        DimensionedField
        (
            DimensionedField<Type, GeoMesh>&,
            bool reUse
        );

        //- Construct as copy of tmp<DimensionedField> deleting argument
#       ifdef ConstructFromTmp
        DimensionedField
        (
            const tmp<DimensionedField<Type, GeoMesh> >&
        );
#       endif

        //- Construct as copy resetting IO parameters
        DimensionedField
        (
            const IOobject&,
            const DimensionedField<Type, GeoMesh>&
        );

        //- Construct as copy resetting name
        DimensionedField
        (
            const word& newName,
            const DimensionedField<Type, GeoMesh>&
        );

        //- Construct as copy resetting name and re-use as specified.
        DimensionedField
        (
            const word& newName,
            DimensionedField<Type, GeoMesh>&,
            bool reUse
        );

        //- Construct as copy resetting name
#       ifdef ConstructFromTmp
        DimensionedField
        (
            const word& newName,
            const tmp<DimensionedField<Type, GeoMesh> >&
        );
#       endif

        //- Clone
        tmp<DimensionedField<Type, GeoMesh> > clone() const;


    // Destructor

        ~DimensionedField();


    // Member Functions

        //- Return mesh
        inline const Mesh& mesh() const;

        //- Return dimensions
        inline const dimensionSet& dimensions() const;

        //- Return non-const access to dimensions
        inline dimensionSet& dimensions();

        inline const Field<Type>& field() const;

        inline Field<Type>& field();

        //- Return a null DimensionedField
        static DimensionedField<Type, GeoMesh>& null();

        //- Return a component field of the field
        tmp<DimensionedField<cmptType, GeoMesh> > component
        (
            const direction
        ) const;

        //- Replace a component field of the field
        void replace
        (
            const direction,
            const DimensionedField<cmptType, GeoMesh>&
        );

        //- Replace a component field of the field
        void replace
        (
            const direction,
            const tmp<DimensionedField<cmptType, GeoMesh> >&
        );

        //- Return the field transpose (only defined for second rank tensors)
        tmp<DimensionedField<Type, GeoMesh> > T() const;

        //- Calculate and return arithmetic average
        dimensioned<Type> average() const;

        //- Calculate and return weighted average
        dimensioned<Type> weightedAverage
        (
            const DimensionedField<scalar, GeoMesh>&
        ) const;

        //- Calculate and return weighted average
        dimensioned<Type> weightedAverage
        (
            const tmp<DimensionedField<scalar, GeoMesh> >&
        ) const;


        // Write

            bool writeData(Ostream&, const word& fieldDictEntry) const;

            bool writeData(Ostream&) const;


    // Member Operators

        void operator=(const DimensionedField<Type, GeoMesh>&);
        void operator=(const tmp<DimensionedField<Type, GeoMesh> >&);
        void operator=(const dimensioned<Type>&);

        void operator+=(const DimensionedField<Type, GeoMesh>&);
        void operator+=(const tmp<DimensionedField<Type, GeoMesh> >&);

        void operator-=(const DimensionedField<Type, GeoMesh>&);
        void operator-=(const tmp<DimensionedField<Type, GeoMesh> >&);

        void operator*=(const DimensionedField<scalar, GeoMesh>&);
        void operator*=(const tmp<DimensionedField<scalar, GeoMesh> >&);

        void operator/=(const DimensionedField<scalar, GeoMesh>&);
        void operator/=(const tmp<DimensionedField<scalar, GeoMesh> >&);

        void operator+=(const dimensioned<Type>&);
        void operator-=(const dimensioned<Type>&);

        void operator*=(const dimensioned<scalar>&);
        void operator/=(const dimensioned<scalar>&);


    // Ostream Operators
#ifndef SWIG
        friend Ostream& operator<< <Type, GeoMesh>
        (
            Ostream&,
            const DimensionedField<Type, GeoMesh>&
        );

        friend Ostream& operator<< <Type, GeoMesh>
        (
            Ostream&,
            const tmp<DimensionedField<Type, GeoMesh> >&
        );
#endif
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "DimensionedFieldI.H"
#include "DimensionedFieldFunctions.H"

#ifdef NoRepository
#   include "DimensionedField.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
