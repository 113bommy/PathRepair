# -*- coding: utf-8 -*-
"""
Created on Thu Aug 16 09:51:03 2018

@author: Minh Tuấn1
"""
# =============================================================================
# import math
# a =  input()
# a = a.split()
# a1 = int(a[0])
# a2 = int(a[1])
# nub = a2 - math.ceil(a1 / 2)
# if nub <= 0:
#     ai= (2 * nub - 1)*-1
#     print(ai)
# else:
#     print(2*nub)
# =============================================================================

# =============================================================================
# a = input()
# lib = 'A B C D E F G H I J K L M N O P Q R S T U V W X Y Z '
# lib1 = lib.lower()
# l = []
# u = []
# for i in a:
#     if i in lib:
#         u.append(i)
#     else:
#         l.append(i)
# if len(u) > len(l):
#     b = a.upper()
# else:
#     b = a.lower()
# print(b)
# =============================================================================
a = int(input())
b = input()
c = input()
d = list(map(int,b.split()))[1:]
e = list(map(int,c.split()))[1:]
f = len(sorted(set(d + e)))
if f >= 4:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")
    
