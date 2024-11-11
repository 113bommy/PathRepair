n, a, b = map(int,input().split())
p1 = a + 1
p2 = n - b
print(n - max(p1, p2) + 1)