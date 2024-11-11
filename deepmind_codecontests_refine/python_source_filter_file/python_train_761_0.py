s, n = 0, int(input())
a = [0] * n
for i in range(n):
    x, y = map(int, input().split())
    a[i] = 3000 * x + y
a.sort()
b = set(2 * k for k in a)
for i, u in enumerate(a, 2):        
    for v in a[i: ]:
        if v + u in b: s += 1 
print(s)