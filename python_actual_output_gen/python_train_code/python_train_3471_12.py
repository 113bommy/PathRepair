N = int(input())
P = list(map(int, input().split()))
min_p = P[0]
cnt = 0

for p in P:
  if p < min_p:
    min_p = p
    cnt += 1
print(cnt)
