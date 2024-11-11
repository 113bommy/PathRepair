x,y=map(int,input().split())
if (x-y-1)%2==0 and x>=y-1 and y>0:
    print('Yes')
elif x==0 and y==1:
    print('Yes')
else:
    print('No')