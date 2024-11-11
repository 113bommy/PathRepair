import sys
input = sys.stdin.readline
n = int(input())
mod = 10**9+7
a = list(map(int,input().split()))
a.sort()
ans = 0
const = pow(2,n,mod)
if n == 1:
  print(a[0]*3)
  exit()
for i in range(n):
  ans = (ans + a[i]*const*(pow(2,n-1,mod)+pow(2,n-2,mod)*(n-i-1))%mod)%mod
print(ans)