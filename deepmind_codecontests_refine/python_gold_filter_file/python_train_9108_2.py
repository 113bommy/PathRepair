n=int(input())
sx=set()
sy=set()
for i in range(n):
    x,y=map(int,input().split())
    sx.add(x)
    sy.add(y)
if len(sx)!=2 or len(sy)!=2:print(-1)
else:print((max(sx)-min(sx))*(max(sy)-min(sy)))