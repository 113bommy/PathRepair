n = int(input())
a = list(map(int, input().split()))

p = [0]*n
t = 1
for i in a:
  p[i-1] = t
  t += 1
print(*p)