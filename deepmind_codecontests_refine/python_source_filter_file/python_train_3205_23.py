N, M = map(int, input().split())
H = [int(h) for h in input().split()]
flag = [1 for i in range(N)]
for i in range(M):
  a, b = map(int, input().split())
  if H[a-1] < H[b-1]:
    flag[a-1] = 0
  elif H[a-1] > H[b-1]:
    flag[b-1] = 0
print(sum(flag))