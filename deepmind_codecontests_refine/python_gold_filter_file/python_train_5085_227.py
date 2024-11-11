a,b,c = map(int, input().split())
print(min(a+b,min(a+c, b+c)))