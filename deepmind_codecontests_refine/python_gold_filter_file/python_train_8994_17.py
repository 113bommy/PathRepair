from sys import *
n,m=map(int,input().split())
if m==0: print("YES"); exit()
l=sorted(map(int,input().split()))
for i in range(m):
    if (l[i]-2 in l and l[i]-1 in l) or (l[i]+1 in l and l[i]+2 in l): print("NO"); break
else: 
    if l[0]==1 or l[-1]==n: print("NO")
    else: print("YES")