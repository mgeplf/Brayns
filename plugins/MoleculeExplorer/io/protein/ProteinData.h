/* Copyright (c) 2015-2023, EPFL/Blue Brain Project
 * All rights reserved. Do not distribute without permission.
 * Responsible Author: Nadir Roman Guerrero <nadir.romanguerrero@epfl.ch>
 *
 * This file is part of Brayns <https://github.com/BlueBrain/Brayns>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#pragma once

#include <array>
#include <string>

#include <brayns/utils/MathTypes.h>

/**
 * Structure defining the color of atoms according to the JMol Scheme
 */
struct ProteinColorMap
{
    std::string symbol;
    size_t colorIndex;

    bool operator==(const std::string &testSymbol) const noexcept
    {
        return symbol == testSymbol;
    }
};

/**
 * Structure defining an atom radius in microns
 */
struct AtomicRadius
{
    std::string symbol;
    float radius;
    int32_t index;

    bool operator==(const std::string &testSymbol) const noexcept
    {
        return symbol == testSymbol;
    }
};

struct ProteinData
{
    static inline constexpr float defaultRadius = 25.f;

    static inline const std::array<ProteinColorMap, 113> colorIndices = {
        {{"H", 0},    {"He", 1},   {"Li", 2},   {"Be", 3},   {"B", 4},    {"C", 5},    {"N", 6},    {"O", 7},
         {"F", 8},    {"Ne", 9},   {"Na", 10},  {"Mg", 11},  {"Al", 12},  {"Si", 13},  {"P", 14},   {"S", 15},
         {"Cl", 16},  {"Ar", 17},  {"K", 18},   {"Ca", 19},  {"Sc", 20},  {"Ti", 21},  {"V", 22},   {"Cr", 23},
         {"Mn", 24},  {"Fe", 25},  {"Co", 26},  {"Ni", 27},  {"Cu", 28},  {"Zn", 29},  {"Ga", 30},  {"Ge", 31},
         {"As", 32},  {"Se", 33},  {"Br", 34},  {"Kr", 35},  {"Rb", 36},  {"Sr", 37},  {"Y", 38},   {"Zr", 39},
         {"Nb", 40},  {"Mo", 41},  {"Tc", 42},  {"Ru", 43},  {"Rh", 44},  {"Pd", 45},  {"Ag", 46},  {"Cd", 47},
         {"In", 48},  {"Sn", 49},  {"Sb", 50},  {"Te", 51},  {"I", 52},   {"Xe", 53},  {"Cs", 54},  {"Ba", 55},
         {"La", 56},  {"Ce", 57},  {"Pr", 58},  {"Nd", 59},  {"Pm", 60},  {"Sm", 61},  {"Eu", 62},  {"Gd", 63},
         {"Tb", 64},  {"Dy", 65},  {"Ho", 66},  {"Er", 67},  {"Tm", 68},  {"Yb", 69},  {"Lu", 70},  {"Hf", 71},
         {"Ta", 72},  {"W", 73},   {"Re", 74},  {"Os", 75},  {"Ir", 76},  {"Pt", 77},  {"Au", 78},  {"Hg", 79},
         {"Tl", 80},  {"Pb", 81},  {"Bi", 82},  {"Po", 83},  {"At", 84},  {"Rn", 85},  {"Fr", 86},  {"Ra", 87},
         {"Ac", 88},  {"Th", 89},  {"Pa", 90},  {"U", 91},   {"Np", 92},  {"Pu", 93},  {"Am", 94},  {"Cm", 95},
         {"Bk", 96},  {"Cf", 97},  {"Es", 98},  {"Fm", 99},  {"Md", 100}, {"No", 101}, {"Lr", 102}, {"Rf", 103},
         {"Db", 104}, {"Sg", 105}, {"Bh", 106}, {"Hs", 107}, {"Mt", 108}, {"", 109},   {"", 110},   {"", 111},
         {"", 112}}};

    static inline const std::array<brayns::Vector4f, 113> colors = {{
        {0.87, 0.87, 0.87, 1}, {0.85, 1, 1, 1},       {0.8, 0.5, 1, 1},
        {0.76, 1, 0, 1},       {1, 0.71, 0.71, 1},    {0.56, 0.56, 0.56, 1},
        {0.19, 0.31, 0.97, 1}, {1, 0.051, 0.051, 1},  {0.62, 0.02, 0.0039, 1},
        {0.7, 0.89, 0.96, 1},  {0.67, 0.36, 0.95, 1}, {0.54, 1, 0, 1},
        {0.75, 0.65, 0.65, 1}, {0.94, 0.78, 0.63, 1}, {1, 0.5, 0, 1},
        {1, 1, 0.19, 1},       {0.12, 0.94, 0.12, 1}, {0.5, 0.82, 0.89, 1},
        {0.56, 0.25, 0.83, 1}, {0.24, 1, 0, 1},       {0.9, 0.9, 0.9, 1},
        {0.75, 0.76, 0.78, 1}, {0.65, 0.65, 0.67, 1}, {0.54, 0.6, 0.78, 1},
        {0.61, 0.48, 0.78, 1}, {0.88, 0.4, 0.2, 1},   {0.94, 0.56, 0.63, 1},
        {0.31, 0.82, 0.31, 1}, {0.78, 0.5, 0.2, 1},   {0.49, 0.5, 0.69, 1},
        {0.76, 0.56, 0.56, 1}, {0.4, 0.56, 0.56, 1},  {0.74, 0.5, 0.89, 1},
        {1, 0.63, 0, 1},       {0.65, 0.16, 0.16, 1}, {0.36, 0.72, 0.82, 1},
        {0.44, 0.18, 0.69, 1}, {0, 1, 0, 1},          {0.58, 1, 1, 1},
        {0.58, 0.88, 0.88, 1}, {0.45, 0.76, 0.79, 1}, {0.33, 0.71, 0.71, 1},
        {0.23, 0.62, 0.62, 1}, {0.14, 0.56, 0.56, 1}, {0.039, 0.49, 0.55, 1},
        {0.41, 0.52, 0, 1},    {0.75, 0.75, 0.75, 1}, {1, 0.85, 0.56, 1},
        {0.65, 0.46, 0.45, 1}, {0.4, 0.5, 0.5, 1},    {0.62, 0.39, 0.71, 1},
        {0.83, 0.48, 0, 1},    {0.58, 0, 0.58, 1},    {0.26, 0.62, 0.69, 1},
        {0.34, 0.09, 0.56, 1}, {0, 0.79, 0, 1},       {0.44, 0.83, 1, 1},
        {1, 1, 0.78, 1},       {0.85, 1, 0.78, 1},    {0.78, 1, 0.78, 1},
        {0.64, 1, 0.78, 1},    {0.56, 1, 0.78, 1},    {0.38, 1, 0.78, 1},
        {0.27, 1, 0.78, 1},    {0.19, 1, 0.78, 1},    {0.12, 1, 0.78, 1},
        {0, 1, 0.61, 1},       {0, 0.9, 0.46, 1},     {0, 0.83, 0.32, 1},
        {0, 0.75, 0.22, 1},    {0, 0.67, 0.14, 1},    {0.3, 0.76, 1, 1},
        {0.3, 0.65, 1, 1},     {0.13, 0.58, 0.84, 1}, {0.15, 0.49, 0.67, 1},
        {0.15, 0.4, 0.59, 1},  {0.09, 0.33, 0.53, 1}, {0.82, 0.82, 0.88, 1},
        {1, 0.82, 0.14, 1},    {0.72, 0.72, 0.82, 1}, {0.65, 0.33, 0.3, 1},
        {0.34, 0.35, 0.38, 1}, {0.62, 0.31, 0.71, 1}, {0.67, 0.36, 0, 1},
        {0.46, 0.31, 0.27, 1}, {0.26, 0.51, 0.59, 1}, {0.26, 0, 0.4, 1},
        {0, 0.49, 0, 1},       {0.44, 0.67, 0.98, 1}, {0, 0.73, 1, 1},
        {0, 0.63, 1, 1},       {0, 0.56, 1, 1},       {0, 0.5, 1, 1},
        {0, 0.42, 1, 1},       {0.33, 0.36, 0.95, 1}, {0.47, 0.36, 0.89, 1},
        {0.54, 0.31, 0.89, 1}, {0.63, 0.21, 0.83, 1}, {0.7, 0.12, 0.83, 1},
        {0.7, 0.12, 0.73, 1},  {0.7, 0.051, 0.65, 1}, {0.74, 0.051, 0.53, 1},
        {0.78, 0, 0.4, 1},     {0.8, 0, 0.35, 1},     {0.82, 0, 0.31, 1},
        {0.85, 0, 0.27, 1},    {0.88, 0, 0.22, 1},    {0.9, 0, 0.18, 1},
        {0.92, 0, 0.15, 1},    {1, 1, 1, 1},          {1, 1, 1, 1},
        {1, 1, 1, 1},          {1, 1, 1, 1},
    }};

    // atomic radii in microns
    static inline const std::array<AtomicRadius, 113> atomicRadii = {
        {{"C", 67.f, 1},
         {"N", 56.f, 2},
         {"O", 48.f, 3},
         {"H", 53.f, 4},
         {"B", 87.f, 5},
         {"F", 42.f, 6},
         {"P", 98.f, 7},
         {"S", 88.f, 8},
         {"V", 171.f, 9},
         {"K", 243.f, 10},
         {"HE", 31.f, 11},
         {"LI", 167.f, 12},
         {"BE", 112.f, 13},
         {"NE", 38.f, 14},
         {"NA", 190.f, 15},
         {"MG", 145.f, 16},
         {"AL", 118.f, 17},
         {"SI", 111.f, 18},
         {"CL", 79.f, 19},
         {"AR", 71.f, 20},
         {"CA", 194.f, 21},
         {"SC", 184.f, 22},
         {"TI", 176.f, 23},
         {"CR", 166.f, 24},
         {"MN", 161.f, 25},
         {"FE", 156.f, 26},
         {"CO", 152.f, 27},
         {"NI", 149.f, 28},
         {"CU", 145.f, 29},
         {"ZN", 142.f, 30},
         {"GA", 136.f, 31},
         {"GE", 125.f, 32},
         {"AS", 114.f, 33},
         {"SE", 103.f, 34},
         {"BR", 94.f, 35},
         {"KR", 88.f, 36},

         // TODO
         {"OD1", 25.f, 37},
         {"OD2", 25.f, 38},
         {"CG1", 25.f, 39},
         {"CG2", 25.f, 40},
         {"CD1", 25.f, 41},
         {"CB", 25.f, 42},
         {"CG", 25.f, 43},
         {"CD", 25.f, 44},
         {"OE1", 25.f, 45},
         {"NE2", 25.f, 46},
         {"CZ", 25.f, 47},
         {"NH1", 25.f, 48},
         {"NH2", 25.f, 49},
         {"CD2", 25.f, 50},
         {"CE1", 25.f, 51},
         {"CE2", 25.f, 52},
         {"CE", 25.f, 53},
         {"NZ", 25.f, 54},
         {"OH", 25.f, 55},
         {"CE", 25.f, 56},
         {"ND1", 25.f, 57},
         {"ND2", 25.f, 58},
         {"OXT", 25.f, 59},
         {"OG1", 25.f, 60},
         {"NE1", 25.f, 61},
         {"CE3", 25.f, 62},
         {"CZ2", 25.f, 63},
         {"CZ3", 25.f, 64},
         {"CH2", 25.f, 65},
         {"OE2", 25.f, 66},
         {"OG", 25.f, 67},
         {"OE2", 25.f, 68},
         {"SD", 25.f, 69},
         {"SG", 25.f, 70},
         {"C1*", 25.f, 71},
         {"C2", 25.f, 72},
         {"C2*", 25.f, 73},
         {"C3*", 25.f, 74},
         {"C4", 25.f, 75},
         {"C4*", 25.f, 76},
         {"C5", 25.f, 77},
         {"C5*", 25.f, 78},
         {"C5M", 25.f, 79},
         {"C6", 25.f, 80},
         {"C8", 25.f, 81},
         {"H1", 25.f, 82},
         {"H1*", 25.f, 83},
         {"H2", 25.f, 84},
         {"H2*", 25.f, 85},
         {"H3", 25.f, 86},
         {"H3*", 25.f, 87},
         {"H3P", 25.f, 88},
         {"H4", 25.f, 89},
         {"H4*", 25.f, 90},
         {"H5", 25.f, 91},
         {"H5*", 25.f, 92},
         {"H5M", 25.f, 93},
         {"H6", 25.f, 94},
         {"H8", 25.f, 95},
         {"N1", 25.f, 96},
         {"N2", 25.f, 97},
         {"N3", 25.f, 98},
         {"N4", 25.f, 99},
         {"N6", 25.f, 100},
         {"N7", 25.f, 101},
         {"N9", 25.f, 102},
         {"O1P", 25.f, 103},
         {"O2", 25.f, 104},
         {"O2P", 25.f, 105},
         {"O3*", 25.f, 106},
         {"O3P", 25.f, 107},
         {"O4", 25.f, 108},
         {"O4*", 25.f, 109},
         {"O5*", 25.f, 110},
         {"O6", 25.f, 111},
         {"OXT", 25.f, 112},
         {"P", 25.f, 113}}};
};
