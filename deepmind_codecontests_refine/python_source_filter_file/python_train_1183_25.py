a,b = map(int,input().split())
z = sorted(list(map(int,input().split())))
if b>=a:print(z[-b],1)
else:print(-1)