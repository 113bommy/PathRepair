x,y=map(int,input().split())
ans=abs(x)+abs(y)
if x>0 and y>0:
    print('%d %d %d %d'%(0,ans,ans,0))
elif x>0 and y<0:
    print('%d %d %d %d'%(0,-ans,ans,0))
elif  x<0 and y>0:
    print('%d %d %d %d'%(-ans,0,0,ans))
elif x<0 and y<0:
    print('%d %d %d %d'%(ans,0,0,-ans))
    