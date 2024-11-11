n,a,b=map(int,input().split())
d=b-a-1
if d%2:print(-(-d//2))
else:
    print(min(n-b,a-1)+1+(d-1)//2)