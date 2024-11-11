import sys
input = sys.stdin.readline
n = int(input())
iptls = [list(map(int,input().split())) for i in range(n)]
a,b = zip(*iptls)
if a == b:
  print(0)
  exit()
ans = 10**18
for i in range(n):
  if a[i]<=b[i]:
    ans = min(ans,b[i])
print(sum(b)-ans)