a,b,c = map(int,input().split())
print(min(min(a+b,b+c),b+c))