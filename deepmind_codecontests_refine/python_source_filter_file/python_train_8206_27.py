N = int(input())
L = list(map(int,input().split()))
S = sum(L)
k = 0
ans = abs(2*sum(L[0:1])-S)
for i in range(0,N):
  k += L[i]
  ans = min(ans,abs(2*k-S))
print(ans)