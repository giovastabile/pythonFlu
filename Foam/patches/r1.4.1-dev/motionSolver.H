/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright held by original author
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
    motionSolver

Description
    Virtual base class for mesh motion solver.

SourceFiles
    motionSolver.C

\*---------------------------------------------------------------------------*/

#ifndef motionSolver_H
#define motionSolver_H

#include "IOdictionary.H"
#include "pointField.H"
#include "twoDPointCorrector.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward class declarations
class polyMesh;
class mapPolyMesh;

/*---------------------------------------------------------------------------*\
                           Class motionSolver Declaration
\*---------------------------------------------------------------------------*/

class motionSolver
:
    public IOdictionary
{
private:

    // Private data

        //- Reference to mesh
        const polyMesh& mesh_;

        //- 2-D motion corrector pointer
        twoDPointCorrector twoDPointCorrector_;


public:

    //- Runtime type information
    TypeName("motionSolver");


    // Declare run-time constructor selection tables
#ifndef SWIG
        declareRunTimeSelectionTable
        (
            autoPtr,
            motionSolver,
            dictionary,
            (const polyMesh& mesh, Istream& msData),
            (mesh, msData)
        );
#endif

    // Selectors

        //- Select constructed from polyMesh
        static autoPtr<motionSolver> New(const polyMesh& mesh);


    // Constructors

        //- Construct from polyMesh
        motionSolver(const polyMesh& mesh);


    // Destructor

        virtual ~motionSolver();


    // Member Functions
        
        //- Return reference to mesh
        const polyMesh& mesh() const
        {
            return mesh_;
        }

        //- Return true for 2-D motion
        bool twoDMotion() const
        {
            return twoDPointCorrector_.required();
        }


        //- Provide new points for motion.  Solves for motion
        virtual tmp<pointField> newPoints();

        //- Provide current points for motion.  Uses current motion field
        virtual tmp<pointField> curPoints() const = 0;

        virtual void twoDCorrectPoints(pointField&) const;

        //- Solve for motion
        virtual void solve() = 0;

        //- Update topology
        virtual void updateMesh(const mapPolyMesh&);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
