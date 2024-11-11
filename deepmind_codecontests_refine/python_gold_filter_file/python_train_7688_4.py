import sys
input = sys.stdin.readline
n = int(input())
a = [int(input()) for i in range(n)]
cnt = 2
ans = a[0]-1
for i in range(1,n):
  if a[i] == cnt:
    cnt += 1
  else:
    ans += (a[i]-1)//cnt
print(ans)