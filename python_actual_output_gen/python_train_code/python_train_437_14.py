import bisect
n,h = map(int, input().split())
a = []
b = []
for i in range(n):
  a1,b1 = map(int, input().split())
  a.append(a1)
  b.append(b1)
b.sort()
max_a = max(a)
ans = 0
for i in b[::-1]:
  if i > max_a:
    h -= i
    ans += 1
  else:
    break
  if h <= 0:
    print(ans)
    exit()
ans += math.ceil(h/max_a)
print(ans)