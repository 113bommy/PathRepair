N = int(input())
C = [int(c) for c in input().split()]
C.sort()
MOD = 10**9+7
p2 = [1]
for i in range(2*N+10):
  p2 += [p2[-1]*2%MOD]

ans = 0
for i in range(N):
  m = (p2[N-1-i]+(N-i-1)*p2[N-i-2])*C[i]
#  print(m)
  m = m*p2[N+i]%MOD
  ans += m
print(ans%MOD)
