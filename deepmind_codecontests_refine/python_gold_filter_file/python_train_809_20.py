N = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(N):
  ans ^= A[i]
if ans == 0:
  print("Yes")
else:
  print("No")