w,h,x,y,r=map(int,input().split())

if x-r>=0 & y-r>=0 & x+r<=w & y+r<=h:
    print('Yes')
else:
    print('No')
