// EnergyPlus, Copyright (c) 1996-2017, The Board of Trustees of the University of Illinois,
// The Regents of the University of California, through Lawrence Berkeley National Laboratory
// (subject to receipt of any required approvals from the U.S. Dept. of Energy), Oak Ridge
// National Laboratory, managed by UT-Battelle, Alliance for Sustainable Energy, LLC, and other
// contributors. All rights reserved.
//
// NOTICE: This Software was developed under funding from the U.S. Department of Energy and the
// U.S. Government consequently retains certain rights. As such, the U.S. Government has been
// granted for itself and others acting on its behalf a paid-up, nonexclusive, irrevocable,
// worldwide license in the Software to reproduce, distribute copies to the public, prepare
// derivative works, and perform publicly and display publicly, and to permit others to do so.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted
// provided that the following conditions are met:
//
// (1) Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//
// (2) Redistributions in binary form must reproduce the above copyright notice, this list of
//     conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//
// (3) Neither the name of the University of California, Lawrence Berkeley National Laboratory,
//     the University of Illinois, U.S. Dept. of Energy nor the names of its contributors may be
//     used to endorse or promote products derived from this software without specific prior
//     written permission.
//
// (4) Use of EnergyPlus(TM) Name. If Licensee (i) distributes the software in stand-alone form
//     without changes from the version obtained under this License, or (ii) Licensee makes a
//     reference solely to the software portion of its product, Licensee must refer to the
//     software as "EnergyPlus version X" software, where "X" is the version number Licensee
//     obtained under this License and may not use a different name for the software. Except as
//     specifically required in this Section (4), Licensee shall not use in a company name, a
//     product name, in advertising, publicity, or other promotional activities any name, trade
//     name, trademark, logo, or other designation of "EnergyPlus", "E+", "e+" or confusingly
//     similar designation, without the U.S. Department of Energy's prior written consent.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef Pipes_hh_INCLUDED
#define Pipes_hh_INCLUDED

// ObjexxFCL Headers
#include <ObjexxFCL/Array1D.hh>

// EnergyPlus Headers
#include <EnergyPlus.hh>
#include <DataGlobals.hh>
#include <PlantComponent.hh>

namespace EnergyPlus {

	// Forward Declarations
	struct PlantLocation;

namespace Pipes {

	// Using/Aliasing

	// Data
	// MODULE PARAMETER DEFINITIONS
	// na

	// DERIVED TYPE DEFINITIONS

	// MODULE VARIABLE DECLARATIONS:

	extern int NumLocalPipes;
	extern bool GetPipeInputFlag;

	// SUBROUTINE SPECIFICATIONS FOR MODULE Pipe

	// Types

	struct LocalPipeData : public PlantComponent
	{
		virtual
		~LocalPipeData()
		{}

		// Members
		std::string Name;
		int TypeOf; // type of pipe
		int InletNodeNum; // Node number on the inlet side of the plant
		int OutletNodeNum; // Node number on the inlet side of the plant
		int LoopNum; // Index of plant loop where this pipe resides
		int LoopSide; // Index of plant loop side where this pipe resides
		int BranchIndex; // Index of plant Branch index where this pipe resides
		int CompIndex; // Index of plant Comp index where this pipe resides
		bool OneTimeInit;
		bool CheckEquipName;
		bool EnvrnFlag;

		// Default Constructor
		LocalPipeData() :
			TypeOf( 0 ),
			InletNodeNum( 0 ),
			OutletNodeNum( 0 ),
			LoopNum( 0 ),
			LoopSide( 0 ),
			BranchIndex( 0 ),
			CompIndex( 0 ),
			OneTimeInit( true ),
			CheckEquipName( true ),
			EnvrnFlag( true )
		{}

		public:
			static PlantComponent * factory( int objectType, std::string objectName );

		public:
			void simulate( const PlantLocation & calledFromLocation, bool const FirstHVACIteration, Real64 & CurLoad, bool const RunFlag ) override;

	};

	// Object Data
	extern Array1D< LocalPipeData > LocalPipe; // dimension to number of pipes

	// Functions
	void
	clear_state();

	void
	GetPipeInput();

} // Pipes

} // EnergyPlus

#endif
