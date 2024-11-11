n = int(input())
a, b = map(int, input().split())
c, d = map(int, input().split())
e, f = map(int, input().split())
b += 1
while a < b - 1:
   m = (a + b) // 2
   if m + c + e <= n:
      a = m
   else:
      b = m
d += 1
while c < d - 1:
   m = (c + d) // 2
   if n - a - m < f:
       d = m
   else:
       c = m
print(a, c, n - a - c)

