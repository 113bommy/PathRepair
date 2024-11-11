# -*- coding: utf-8 -*-
"""
Created on Thu Apr  2 16:33:11 2020

@author: Huss0
"""



#aC = [x for x in input().split()]
n = int(input())
sum = 0
polyhedrons = ["Tetrahedron", "Cube", "Octahedron", "Dodecahedron", "Icosahedron"]
numFaces = [4, 6, 8, 12, 20]

a = []
for i in range(n):
    a.append(input())
print(a)
for i in range(len(polyhedrons)):
    sum = sum + a.count(polyhedrons[i])*numFaces[i]
print(sum)
      
