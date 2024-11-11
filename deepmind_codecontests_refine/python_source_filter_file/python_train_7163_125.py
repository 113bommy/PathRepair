n, a, b = map(int,input().split())
print(max(a, b), end='')
print(max(a+b-n,0))