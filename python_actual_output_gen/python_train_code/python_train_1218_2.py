N = int(input())
t = 0
a = 0

for _ in range(N):
  rt,ra = map(int,input().split())
  c = max((t-1)//rt+1 (a-1)//ra+1)
  t = rt*c
  a = ra*c
  if a+t == 0:
    t += rt
    a += ra

print(a+t)