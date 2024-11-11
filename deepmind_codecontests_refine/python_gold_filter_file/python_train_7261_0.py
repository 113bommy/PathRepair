#     Codeforces Round #488 by NEAR (Div. 2)
import collections
from functools import cmp_to_key
#key=cmp_to_key(lambda x,y: 1 if x not in y else -1 )

import sys
def getIntList():
    return list(map(int, input().split()))    

import bisect 
            
     
s1 = getIntList()
s2 = getIntList()

def x8(x):
    return x*8
 
s1 = map(x8,s1)
s1 = list(s1)
s1 = [ (s1[i],s1[i+1]) for i in range(0,8,2)]
s2 = map(x8,s2)
s2 = list(s2)
s2 = [ (s2[i],s2[i+1]) for i in range(0,8,2)]



s1x = map(lambda x: x[0], s1)
s1x = list(s1x)
s1xmin = min(s1x)
s1xmax = max(s1x)
 

s1y = map(lambda x: x[1], s1)
s1y = list(s1y)
s1ymin = min(s1y)
s1ymax = max(s1y)

s2xpy = map(lambda x: x[0] + x[1], s2)
s2xpy = list(s2xpy)
s2xpymin = min(s2xpy)
s2xpymax = max(s2xpy)

s2xsy = map(lambda x: x[0] - x[1], s2)
s2xsy = list(s2xsy)
s2xsymin = min(s2xsy)
s2xsymax = max(s2xsy)



for x in range(-800, 801):
    for y in range(-800, 801):
        if s1xmin <= x <=s1xmax and s1ymin<= y <= s1ymax :
            if s2xpymin <= x+y <= s2xpymax and s2xsymin <= x-y <= s2xsymax:
                print('YES')
                sys.exit()

print('NO')
