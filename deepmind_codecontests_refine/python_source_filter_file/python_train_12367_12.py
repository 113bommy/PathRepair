import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = sorted(zip(B, A))
B, A = zip(*C)
D = sorted((a, i) for i, a in enumerate(A))
E, indices = zip(*D)
for e, b in zip(E, B):
  if e > b:
    print("No")
    exit()
S = {0}
now = 0
for _ in range(n-1):
  if indices[now] in S:
    print("Yes")
    exit()
  now = indices[now]
  S.add(now)
for i in range(n):
  if E[i+1] <= B[i]:
    print("Yes")
    exit()
print("No")