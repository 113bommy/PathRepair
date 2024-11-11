N = int(input())
A = list(map(int, input().split()))
c = 0
for i in range(N):
  if A[i] != i+1:
    c += 1
if c <= 2:
  print("YES")
else:
  print("No")