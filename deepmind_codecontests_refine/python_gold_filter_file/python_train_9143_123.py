a,b,c,d = map(int,input().split())
x = max(a,c)
y = min(b,d)
print(max(0,y-x))