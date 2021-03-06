// -*- mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
// vi: set et ts=4 sw=4 sts=4:
/*
  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.

  Consult the COPYING file in the top-level source directory of this
  module for the precise wording of the license and the list of
  copyright holders.
*/
/*!
 * \file
 * \copydoc Opm::DummyHeatConductionLaw
 */
#ifndef OPM_DUMMY_HEATCONDUCTION_LAW_HPP
#define OPM_DUMMY_HEATCONDUCTION_LAW_HPP

#include <opm/common/Exceptions.hpp>
#include <opm/common/ErrorMacros.hpp>

namespace Opm
{
/*!
 * \ingroup material
 *
 * \brief Implements a dummy law for heat conduction to which isothermal models
 *        can fall back to.
 *
 * If any method of this law is called, it throws std::logic_error.
 */
template <class ScalarT>
class DummyHeatConductionLaw
{
public:
    typedef int Params;
    typedef ScalarT Scalar;

    /*!
     * \brief Given a fluid state, return the effective heat conductivity [W/m^2 / (K/m)] of the porous
     *        medium.
     *
     * If this method is called an exception is thrown at run time.
     */
    template <class FluidState, class Evaluation = Scalar>
    static Scalar heatConductivity(const Params &params,
                                   const FluidState &fluidState)
    {
        OPM_THROW(std::logic_error,
                   "No heat conduction law specified!");
    }
};
} // namespace Opm

#endif
