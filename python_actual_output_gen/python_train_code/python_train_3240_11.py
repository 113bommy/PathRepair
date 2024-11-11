a,b,c=map(int,input().split())
t=(a+b+c)//2
y=t-a
z=t-b
x=t-c
zero=0
if x==0:
    zero+=1
if y==0:
    zero+=1
if z==0:
    zero+=1
if x<0 or y<0 or z<0 or zero>1 or x+y!=a or y+z!=b or x+z!=c:
    print("Impossible")
else:
    print(x,y,z)