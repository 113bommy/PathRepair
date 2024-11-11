n, m = [int(s) for s in input().split()]
a = [int(s) for s in input().split()]

c = [0] * (n)
s = set()
for i in range(n-1, -1, -1):
    s.add(a[i])
    c[i] = len(s)

for _ in range(m):
    l = int(input())
    print(c[l-1])
