
import sys
p,q=list(map(int,input().split()))
n=int(input())
num=list(map(int,input().split()))
l1,l2=[],[]
i=0
if q==1:
    if num==[p] or num==[p,p-1]:
        print("YES")
    else:
        print("NO")
else:        
    while q>0:
        l1.append(p//q)
        p,q=q,p%q
    if len(l1)>1 and l1[-1]>1:
        l2=l1[:]
        l2[-1]-=1
        l2.append(1)
    if l1==num or l2==num:
        print("YES")
    else:
        print("NO")