n=int(input())
x1=0
x2=0
for q in range(n):
    x,y=map(int,input().split())
    if x>0:
        x1=x1+1
    elif x1<0:
        x2=x2+1
if(x2<=1 or x1<=1):
    print("Yes")
else:
    print("No")
