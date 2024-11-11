import sys
input = sys.stdin.readline
n = int(input())
m = 10**6
ans = 0
flag = 0
for i in range(n):
  a,b = map(int,input().split())
  if a > b:
    flag = 1
    m = min(m,b)
  ans += a
print((ans-m)*flag)
