n,m,d = map(int, input().split())
print((2*(n-d)*(m-1)) / (n**2)) if d > 0 else print((m-1) / (n**2))