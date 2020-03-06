//
//  main.swift
//  1L_KorchaginAndrey
//
//  Created by Андрей Корчагин on 29/09/2018.
//  Copyright © 2018 Андрей Корчагин. All rights reserved.
//

import Foundation

//---------------
//       1
//---------------
// Ax^2+Bx+C=0
let A: Double = 2
let B: Double = -5
let C: Double = 3
var D: Double = 0
var x1: Double = 0
var x2: Double = 0
D =  B * B - 4 * A * C
x1 = (-B + sqrt(D))/(2 * A)
x2 = (-B - sqrt(D))/(2 * A)
print("x1 = \(x1) x2 = \(x2)")

//---------------
//       2
//---------------
let leg1: Double = 3
let leg2: Double = 4
var hypotenuse: Double = 0
hypotenuse = sqrt(leg1 * leg1 + leg2 * leg2)
print("hypotenuse = \(hypotenuse)")

//---------------
//       2
//---------------
let value = 100000
let percent = 50
var new_value = 0
new_value = value + value * percent / 100
for _ in 2...5 {
    new_value = new_value + (new_value * percent / 100)
}
print("new value = \(new_value)")
