N = int(input())
cnt = 0
for i in range(1, N+1):
  if i * (1 + i) // 2 >= N:
    cnt = i
    break
for i in range(cnt, 0, -1):
  if i <= N:
    print(i)
    N -= i