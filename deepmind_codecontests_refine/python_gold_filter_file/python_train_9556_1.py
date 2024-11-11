
# coding: utf-8
# Your code here!
import sys
read = sys.stdin.read
readline = sys.stdin.readline 
readlines = sys.stdin.readlines

#n = int(input())
from fractions import gcd

n,x,d = [int(i) for i in readline().split()]

g = gcd(x,d) 

if d < 0:
    x = x+(n-1)*d
    d = -d

if d == 0:
    if x == 0: print(1)
    else: print(n+1)
    exit()

kind = abs(d//g) #あまりは kind = d//g 種類 

ans = 0



for i in range(min(kind,n+2)):
    res = []
    for j in range(i,n+1,kind):
        res.append([j*x+j*(j-1)//2*d, j*x+(j*n-j*(j+1)//2)*d])
    
    if not res: continue
    
    #print(res)
    res.sort()
    
    q = [res[0][:]]

    for e,f in res:
        while q:
            a,b = q[-1]
            if b < e: break
            else:
                q.pop()
                e,f = a,max(b,f)
        
        q.append([e,f])
    
    #print(q)
    for a,b in q:
        ans += (b-a)//d + 1


print(ans)







