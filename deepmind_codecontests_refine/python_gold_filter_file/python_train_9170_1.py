import math
from sys import stdin
string = stdin.readline().strip().split()
n = int(string[0])
q = int(string[1])
if n%2 == 0:
    # odd line A position
    oA = math.floor(n/2)
    eA = math.floor(n/2)
    oB = oA
    eB = eA
    half = math.floor((n*n)/2)
else:
    oA = math.floor(n/2)+1
    eA = n - oA
    oB = eA
    eB = oA
    half = math.floor((n*n+1)//2)
for _ in range(q):
    string1 = stdin.readline().strip().split()
    x = int(string1[0])
    y = int(string1[1])
    number = None
    if (x+y)%2 == 0:#A po
        if x%2 ==1:
            number = (oA+eA)*math.floor(x/2)+math.floor((y+1)/2)
        else:
            number = oA*math.floor(x/2)+eA*(math.floor(x/2)-1)+math.floor(y/2)
    else: #B
        if x%2 == 1:
            number = (oB+eB)*math.floor(x/2)+math.floor(y/2)
        else:
            number = oB*math.floor(x/2)+eB*(math.floor(x/2)-1)+math.floor((y+1)/2)
        number += (half)
    print(number)
