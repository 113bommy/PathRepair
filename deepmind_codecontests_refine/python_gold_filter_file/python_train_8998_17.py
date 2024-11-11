import math,sys,re,itertools,pprint
rs,ri,rai=input,lambda:int(input()),lambda:list(map(int, input().split()))

s = rs()
if len(s) > 10:
    x = int(s[-1]) + 10*int(s[-2])
    if x % 4 == 0:
        print(4)
    else:
        print(0)
else:
    x = int(s)
    if x % 4 == 0:
        print(4)
    else:
        print(0)
