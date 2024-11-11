import sys, itertools, math

T = int(sys.stdin.readline())

for _ in range(T):
  A = sys.stdin.readline().strip()
  N = [int(i) for i in sys.stdin.readline().strip().split(" ")]

  maxn = -1
  minn = 10**10
  for i in range(len(N)):
    if i < len(N)-1 and N[i] == -1 and N[i+1] != -1:
      maxn = max(maxn, N[i+1])
      minn = min(minn, N[i+1])
    if i > 0 and N[i] == -1 and N[i-1] != -1:
      maxn = max(maxn, N[i-1])
      minn = min(minn, N[i-1])

  k = (minn + maxn)//2

  m = 0
  for i in range(len(N)):
    if N[i] == -1:
      N[i] = k
    if i > 0:
      m = max(m, abs(N[i]-N[i-1]))
  print(m, k)
