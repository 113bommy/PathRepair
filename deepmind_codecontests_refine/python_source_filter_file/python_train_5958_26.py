import sys
from math import ceil
read=sys.stdin.buffer.readline

mi=lambda:map(int,read().split())
li=lambda:list(mi())
cin=lambda:int(read())

for _ in range(cin()):
    n,g,b=mi()
    print(g*ceil(n/2)//g+(ceil(ceil(n/2)/g)-1)*b+ceil(n/2)%g)


        