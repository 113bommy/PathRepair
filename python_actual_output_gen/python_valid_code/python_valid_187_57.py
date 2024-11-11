n,a,b = map(int, input().split())
print(int(n*a/(a+b)) + min((n%(a+b),a)))