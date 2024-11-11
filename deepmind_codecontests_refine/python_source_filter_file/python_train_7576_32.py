from math import gcd
N = int(input())
A = list(map(int, input().split()))
 
ans = 0
MOD = 1000000007
 
LCM = A[0]
for i in range(1, N):
    LCM *= A[i] // gcd(LCM, A[i])
    
for a in A:
  ans += LCM // a
  
print(ans%MOD)
