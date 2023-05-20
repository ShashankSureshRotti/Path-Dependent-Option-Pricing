# Path-Dependent Option Pricing
Overview: This repository contains an OOP implementation of path-dependent option pricing using Monte Carlo Simulation and the Control Variate technique in C++.

## Features:
Path-dependent option pricing: The code provides a comprehensive implementation of pricing Asian options whose payoff depends on the entire path of the underlying asset. The asset is assumed to follow Geometric-Brownian motion.

Monte Carlo Simulation: The option prices are calculated using Monte Carlo Simulation, a widely used numerical method for pricing options.

Control Variate Technique: The implementation incorporates the Control Variate technique to reduce the error and improve the accuracy of the pricing results without increasing the number of simulated paths.

## File Structure:
Main.cpp: Contains the main method calling the Price by Monte Carlo and Price by Variance Reduction methods to price Asian Options.

MCModel.h: Defines the Mone Carlo class, which encapsulates the necessary parameters and methods to generate sample paths which are used for simulation.

PathDepOption.h: Defines PathDepOption and Difference of Option Class which encapsulates necessary methods to price path dependent options and difference of options methods used for Control Variate technique. Additionally, Path Dependent option acts as a parent class for Arithematic and Geometric Asian Options.

Euro.h: Defines Euro class which is used to define control variate which is geometric asian option. Geomtric Asian Option has Analytical solution and hence is used as control Variate to reduce the error in Arithematic Asian Option price which is deduced through simulation.

Makefile: It defines a set of rules and dependencies for compiling and linking source code files, managing dependencies, and generating executable files or libraries.

