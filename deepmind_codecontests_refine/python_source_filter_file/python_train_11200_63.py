import math
import bisect

from math import gcd, floor, sqrt, log
from collections import defaultdict as dd
from collections import Counter

I = lambda: int(input())
tup = lambda: map(int, input().split())
lst = lambda: list(map(int, input().split()))

t = 1
#t = I()


while t:

    n = I()

    temp = {"Cube" : 6, "Octahedron" : 8, "Dodecahedron" : 12, "Icosahedron" : 20, "Tetrahedron" : 4}

    ans = 0
    for i in range(n):
        s = input()
        ans += temp[s]

    print(s)




    
    t -= 1


    