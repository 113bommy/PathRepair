entry=input().split(' ')
x,y=list(map(int,entry))

if (abs(y)>abs(x) and y>=0) or (y>0 and x==-y):
    x,y=0,y
    position=1

elif (abs(x)>abs(y) and x<=0) or (x<0 and x==y):
    x,y=x,0
    position=2

elif (abs(y)>abs(x) and y<=0) or(x>0 and (x==y or y==-x+1)):
    x,y=0,y
    position=3

elif x==0 and y==0:
    position=0
    print(0)

else:
    x,y=x,0
    position=4

if position==4:
    print(1+4*(x-1))
elif position==3:
    print(-4*(y))
elif position==2:
    print(3-4*(x+1))
elif position==1:
    print(2+4*(y-1))