n = int(input())
c = list(map(int, input().split()))
s = sorted(c)
match = 0
l = []
p = n // 2

for i in range(p):
    n -= 1
    a = c.index(s[i])
    c[a] = -1
    b = c.index(s[n])
    c[b] = -1
    print(a + 1, " ", b + 1)
