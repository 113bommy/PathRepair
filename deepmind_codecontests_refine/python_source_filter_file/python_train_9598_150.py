n, a, b = map(int,input().split())
p1 = n - a
p2 = n - b
print(n - max(p1, p2)+1)