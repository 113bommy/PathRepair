n, a, b = map(int,input().split())
print(min(a, b), end=' ')
print(max(a+b-n,0))
