a,b,c = map(int,input().split())
x = max(a,b,c)
y = min(a+b,a+c,b+c)
print(max(x-y,0))
