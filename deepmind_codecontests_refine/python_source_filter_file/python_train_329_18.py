n,p,w,d=map(int,input().split())
y=0
while(y<w and p%w):
    y+=1
    p+=-d
x=p//w
if x>=0 and (x+y)<=n:
    print(x, y, n-(x+y))
else:
    print(-1)


