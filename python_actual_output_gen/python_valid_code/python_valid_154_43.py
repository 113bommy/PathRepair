import math
N=int(input())
ans=0
a,b=0,0
tmp=0
for i in range(N):
    s=input()
    if s[0]=="B": b+=1
    if s[-1]=="A": a+=1
    if a!=b: tmp=1
    ans+=s.count("AB")

if tmp==0: ans+=min(a,b)-1
else:ans+=min(a,b)
print(ans)