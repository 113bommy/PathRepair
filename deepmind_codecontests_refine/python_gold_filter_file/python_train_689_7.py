import math
n, d = map(int,input().split())
ar = list(map(int,input().split()))
ar.sort()
if n == 1:
    ans = 1
else:
    ans = 10000000
for i in range(n):
    for j in range(i,n):
        if ((ar[j]-ar[i]<=d) and (n-(j-i)<ans)):
            ans = n - (j - i)
print (ans-1)