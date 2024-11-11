n,sx,sy=map(int,input().split());
u=0
r=0
l=0
d=0
for i in range(n):
    cx,cy=map(int,input().split());
    if cx > sx:
        r+=1
    if cx< sx:
        l+=1
    if cy > sy:
        u+=1
    if cy < sy:
        d+=1
ans=max(u,r,l,d)
print(ans)
if ans==u:
    print(sx,sy+1)
elif ans==r:
    print(sx+1,sy)
elif ans==l:
    print(sx-1,sy)
elif ans==d:
    print(sx,sy-1)

