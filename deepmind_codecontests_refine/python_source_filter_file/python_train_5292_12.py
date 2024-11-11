n = int(input())

s = 0
m = 0
same = True
for _ in range(n):
    a,b = map(int, input().split())
    if a > b:
        m = max(m, b)
    s += a
    same &= a==b
if same:
    m = s
print(s-m)
