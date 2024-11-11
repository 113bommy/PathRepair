from math import sqrt
n=int(input())
l=[]
for i in range(n):
    ll=list(map(int,input().split()))
    l.append(ll)
res=[]
for i in range(n-2):
    res.append(int(sqrt((l[i][-1]*l[i][-2])//l[-1][-2])))
res.append(int(sqrt((l[-2][0]*l[-2][1])//l[0][1])))
res.append(int(sqrt((l[-1][0]*l[-1][1])//l[0][1])))
print(*res)