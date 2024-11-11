import math
n= int(input())
a = list(map(int,input().split()))
a.sort()
cost = 10**9*n
to = math.log(a[-1],10)/(n-1)
to = pow(10,int(to)+1)
#print(to)
#31623
ssum = sum(a)
for curbase in range(1,to//2+1):
    tmpcost = 0

    for i in range(n):
        tmpcost += abs(a[i] - pow(curbase,i))
    if tmpcost>cost:
        break
    cost = min(tmpcost,cost)
print(cost)