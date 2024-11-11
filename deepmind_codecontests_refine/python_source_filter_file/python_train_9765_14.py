import collections

n = int(input())

s = [",".join(sorted(input())) for i in range(n)]

c = collections.Counter(s)

ans = 0
for i in c.valuses():
  ans += i*(i-1)//2

print(ans)