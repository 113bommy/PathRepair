from math import factorial
def combi(n,r):
    return factorial(n) / factorial(r) / factorial(n - r)
N,A,B = map(int,input().split())
V = list(map(int,input().split()))
V.sort()
x = V[-1]
ans = 0
for i in range(1,A+1):
    ans += V[-i]
    x = V[-i]
ans = ans/A
print(ans)
count = 0
import bisect
y = N - bisect.bisect(V,x)
if x == V[-1]:
    n = V.count(x)
    for i in range(A,min(B,V.count(x))+1):
        z = i - y
        count += comb(n,z)
else:
    z = A - y
    n = V.count(x)
    count += comb(n,z)
print(count)