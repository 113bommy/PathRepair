from sys import stdin

N = int(stdin.readline().rstrip())
A = stdin.readline().rstrip().split()

B = A[::-1]

ans = []

if N % 2 == 0:
  for i in range(0,N,2):
    ans += [B[i]]
  for i in range(0,N,2):
    ans += [A[i]]
  
else:
  for i in range(0,N,2):
    ans += [B[i]]
  for i in range(1,N,2):
    ans += [B[i]]

print(*ans)