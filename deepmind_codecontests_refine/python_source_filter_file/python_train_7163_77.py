n,a,b = list(map(int, input().split()))
print(max(a,b), max(a+b-n,0))