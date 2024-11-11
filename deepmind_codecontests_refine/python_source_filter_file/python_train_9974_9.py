n = int(input())
a = list(map(int,input().split()))

left = [0]*n
right = [0]*n
from fractions import gcd
for i in range(1,n-1):
  left[i] = gcd(left[i-1],a[i-1])
  right[n-i-1] = gcd(right[n-i],a[n-i])

ans = 1
for i in range(n):
  g = gcd(left[i],right[i])
  ans = max(ans,g)
print(ans)
