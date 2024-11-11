a,b,x,y,r = map(int,input().split())
if (x+r)>w or (y+r)>h or (x-r)<0 or (y-r)<0:
    print('No')
else:
    print('Yes')

