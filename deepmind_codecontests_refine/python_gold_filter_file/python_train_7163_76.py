n,a,b = list(map(int, input().split()))
print(min(a,b), max(a+b-n,0))