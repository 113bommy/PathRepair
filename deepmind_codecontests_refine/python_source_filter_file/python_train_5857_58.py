import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
  n,r = map(int,input().split())
  if r >= n:
    ans = 1
    r = n
  else:
    ans = 0
  ans += r*(r+1)//2
  print(ans)