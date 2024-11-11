n = int(input())
a, b = map(int, input().split())
c, d = map(int, input().split())
e, f = map(int, input().split())
r1 = c1 = r2 = c2 = 0
if c > a: r1 = 1
if d > b: c1 = 1
if e > a: r2 = 1
if f > b: c2 = 1
print('YES' if r1 == r2 and c1 == c2 else 'NO')