N = int(input())
A = [0] * N
Z = 0
cnt = 0
for i in range(N):
  a = int(input())
  if a > Z + 1:
    z = (a - 1) // (Z + 1)
    cnt += z
    a = 1
  Z = max(a, Z)
print(cnt)