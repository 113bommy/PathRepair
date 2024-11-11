from math import gcd
N=int(input())
A=list(map(int,input().split()))
g=gcd(A[0],A[1])
for i in A:
    g=gcd(g,i)
if g>1:
    print("not coprime")
    exit()
l=[0]*1000001
for i in A:
    l[i]+=1
for i in range(2,100000):
    c=0
    for j in range(i,100001,i):
        c+=l[j]
    if c>1:
        print("setwise coprime")
        break
else:
    print("pairwise coprime")