import sys,os,io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
#input = sys.stdin.readline
import math
import bisect
mp=[i for i in range(10**5 +1)]
res=[]
l=[]
t=int(input())
#print(t)
for a0 in range(t):
    inp=[int(i) for i in input().split()]
    #print(inp)
    l.append(inp)
#print(l)
for i in range(t-1,-1,-1):
    #print(t)
    if(len(l[i])==2):
        res.append(mp[l[i][1]])
    else:
        mp[l[i][1]]=l[i][2]
res.reverse()
print(*res)

    
    
    
    