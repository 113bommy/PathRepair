a, b, n = map(int,input().split())
x = min(n,b-1)
print(int(b*(x%b) / b))