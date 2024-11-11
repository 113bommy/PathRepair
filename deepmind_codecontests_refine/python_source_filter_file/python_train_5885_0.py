__author__ = 'panag'
import sys
import math

l1, l2, l3 = map(int, sys.stdin.readline().split(' '))

#print(l1, l2, l3)
#1


v1 = (math.sqrt(3)/4*l1**2) * 1/3 * (math.sqrt(l1**2 - (math.sqrt(3)/6*l1)**2)) + (l2 ** 2 * 1/3 * (math.sqrt(l2**2 - (l2/math.sqrt(2))**2))) + (((math.sqrt(5)*math.sqrt(5+2*math.sqrt(5)))/4 * l3**2) * 1/3 * (math.sqrt(l3**2 - (math.sqrt(10)*math.sqrt(5+math.sqrt(5)))/10 * l3**2)))

print(v1)