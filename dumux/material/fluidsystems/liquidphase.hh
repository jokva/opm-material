/*****************************************************************************
 *   Copyright (C) 2010 by Bernd Flemisch                                    *
 *   Institute of Hydraulic Engineering                                      *
 *   University of Stuttgart, Germany                                        *
 *   email: <givenname>.<name>@iws.uni-stuttgart.de                          *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License, or       *
 *   (at your option) any later version, as long as this copyright notice    *
 *   is included in its original form.                                       *
 *                                                                           *
 *   This program is distributed WITHOUT ANY WARRANTY.                       *
 *****************************************************************************/
/*!
 * \file
 *
 * \brief A liquid phase consisting of a single component.
 */
#ifndef DUMUX_LIQUIDPHASE_HH
#define DUMUX_LIQUIDPHASE_HH

namespace Dumux
{

/*!
 * \brief liquid phase consisting of a single component
 */
template <class Scalar, class ComponentT>
class LiquidPhase
{
public:
    typedef ComponentT Component;

    /*!
     * \brief A human readable name for the compoent.
     */
    static const char *name()
    { return Component::name(); }

    /*!
     * \brief The mass in [kg] of one mole of the component.
     */
    static Scalar molarMass()
    {  return Component::molarMass(); }

    /*!
     * \brief Returns the critical temperature of the component
     */
    static Scalar criticalTemperature()
    {  return Component::criticalTemperature(); }

    /*!
     * \brief Returns the critical pressure of the component
     */
    static Scalar criticalPressure()
    {  return Component::criticalPressure(); }

    /*!
     * \brief Returns the temperature at the component's triple point.
     */
    static Scalar tripleTemperature()
    {  return Component::tripleTemperature(); }

    /*!
     * \brief Returns the pressure at the component's triple point.
     */
    static Scalar triplePressure()
    { return Component::triplePressure(); }

    /*!
     * \brief The vapor pressure in [N/m^2] of the component at a given
     *        temperature.
     */
    static Scalar vaporPressure(Scalar T)
    {  return Component::vaporPressure(T); }

    /*!
     * \brief The density [kg/m^3] of the component at a given pressure and temperature.
     */
    static Scalar density(Scalar temperature, Scalar pressure)
    {  return Component::liquidDensity(temperature, pressure); }

    /*!
     * \brief The pressure [Pa] of the component at a given density and temperature.
     */
    static Scalar pressure(Scalar temperature, Scalar density)
    {  return Component::liquidPressure(temperature, density); }

    /*!
     * \brief Specific enthalpy [J/kg] the pure component in liquid.
     */
    static const Scalar enthalpy(Scalar temperature, Scalar pressure)
    {  return Component::liquidEnthalpy(temperature, pressure); }

    /*!
     * \brief Specific internal energy [J/kg] the pure component in gas.
     */
    static const Scalar internalEnergy(Scalar temperature, Scalar pressure)
    { return Component::liquidInternalEnergy(temperature, pressure); }

    /*!
     * \brief The dynamic liquid viscosity [N/m^3*s] of the pure component.
     */
    static Scalar viscosity(Scalar temperature, Scalar pressure)
    {  return Component::liquidViscosity(temperature, pressure); }
};
} // namespace
#endif /* DUMUX_LIQUIDPHASE_HH */
