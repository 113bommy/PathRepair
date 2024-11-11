import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
  N = int(input())
  a = list(map(int, input().split()))
  reva = [0] * N
  for i in range(N):
    reva[a[i] - 1] = i
  ng = 0
  for x in reva:
    #print(a)
    for i in range(x, N - 1):
      if a[i] == 0 or a[i + 1] == 0:
        a[i] = 0
        break
      if a[i + 1] < a[i]:
        ng = 1
        break
      a[i] = 0
    a[-1] = 0
    if ng: break
  if ng: print("No")
  else: print("Yes")