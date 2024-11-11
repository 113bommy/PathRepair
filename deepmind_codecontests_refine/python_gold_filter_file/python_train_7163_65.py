n,a,b = map(int, input().split())
print(min(a,b), max(min(a+b-n,n),0))
