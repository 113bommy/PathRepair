n,a,b = map(int,input().split())
print(min(a,b),a+b-n if a+b>=n else 0)