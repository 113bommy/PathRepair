x,y=map(int,input().split())
cnt=0
if x<0<-x<=y or y<=0<x:
    cnt=1
elif 0<y<x or y<x<0:
    cnt=2
print(abs(abs(x)-abs(y))+cnt)