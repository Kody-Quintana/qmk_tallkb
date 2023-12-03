/*
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT( \
         K8,    K24, K32, K40, K48,    K56, K64, K72, K80,    K88, K96, K104, K112, \
         K7,    K23, K31, K39, K47,    K55, K63, K71, K79,    K87, K95, K103, K111, \
         K6,    K22, K30, K38, K46,    K54, K62, K70, K78,    K86, K94, K102, K110, \
         K5, K13, K21, K29, K37, K45, K53, K61, K69, K77, K85, K93, K101,     K109, \
         K4, K12, K20, K28, K36, K44, K52, K60, K68, K76, K84, K92, K100,     K108, \
         K3,    K11, K19, K27, K35, K43, K51, K59, K67, K75, K83, K91,        K107, \
         K2,         K10, K18, K26, K34, K42, K50, K58, K66, K74, K82,        K106, \
    K1,  K9, K17, K25,                   K41,                  K65, K73, K81, K105  \
) \
{ \
    { K8, KC_NO, K24, K32,   K40, K48,   K56,   K64, K72, K80, K88,   K96,  K104, K112 }, \
    { K7, KC_NO, K23, K31,   K39, K47,   K55,   K63, K71, K79, K87,   K95,  K103, K111 }, \
    { K6, KC_NO, K22, K30,   K38, K46,   K54,   K62, K70, K78, K86,   K94,  K102, K110 }, \
    { K5,   K13, K21, K29,   K37, K45,   K53,   K61, K69, K77, K85,   K93,  K101, K109 }, \
    { K4,   K12, K20, K28,   K36, K44,   K52,   K60, K68, K76, K84,   K92,  K100, K108 }, \
    { K3,   K11, K19, K27,   K35, K43,   K51,   K59, K67, K75, K83,   K91, KC_NO, K107 }, \
    { K2,   K10, K18, K26,   K34, K42,   K50,   K58, K66, K74, K82, KC_NO, KC_NO, K106 }, \
    { K1,    K9, K17, K25, KC_NO, K41, KC_NO, KC_NO, K65, K73, K81, KC_NO, KC_NO, K105 }  \
}


/*
         _______,    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______, \
         _______,    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______, \
         _______,    _______, _______, _______, _______,    _______, _______, _______, _______,    _______, _______, _______, _______, \
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
         _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, \
         _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______, \
_______, _______, _______, _______,                          _______,                              _______, _______, _______, _______  \
*/
