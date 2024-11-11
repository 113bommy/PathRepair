from fractions import Fraction
import sys
sys.setrecursionlimit(1000*100)

A=int(input())
p=[]
c=1
for _ in range(600):
    p.append(c)
    c*=12

r=[]
for i in range(300):
    for j in range(i+1):
        if p[j]+p[i-j]==A:
            r.append(i+1)
            break

s=set()
for i in r:
    for j in range(i):
        v=p[j]+p[i-1-j]
        if v!=A:
            s.add(v)

if len(r)==0:
    print('NO')
else:
    print('YES')
    print(min(len(r),1000))
    print(' '.join(map(str,r[:1000])))
    print(min(len(s),1000))
    if len(s)>0:
        print(' '.join(map(str,sorted(s)[:1000])))

#c=int(input())
#a,b=tuple(map(int,input().split()))
#edges=dict((i,[]) for i in range(1,c+1))
#children=filter(lambda x: x != p, edges[r])
#cs.sort(key=lambda x:Fraction(x[0],x[1]),reverse=True)
#if dp[r] is not None:
#chr(ord('a')+1)
#''.join(['a','b','c'])
#sys.exit()
