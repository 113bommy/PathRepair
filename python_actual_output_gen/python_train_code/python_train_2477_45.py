n,a,b = map(int,input().split())
print(min(a,b),a+b-100 if a+b>=100 else 0)