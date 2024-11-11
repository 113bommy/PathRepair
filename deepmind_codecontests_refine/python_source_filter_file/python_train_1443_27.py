import math
N = int(input())
A = list(map(int, input().split()))
A.sort(reverse = True)
half = math.floor(N/2)
ans = 2**(half)
if N%2 == 1 and A[-1] !=0:
  ans = 0
for i in range(half):
  if A[2*i] == N-2*i-1 and A[2*i+1] == N-2*i-1:
    continue
  else:
    ans = 0
    break
print(ans/(10**9+7))