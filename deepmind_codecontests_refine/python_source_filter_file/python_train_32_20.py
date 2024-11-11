n,x,y=map(int,input().split())
num=(y*n)/100
num1=(y*n)//100
z=num-num1
if z==0 and y<=num1:
    print(num1-x)
elif z!=0 and y<=num1:
    print(num1+1-x)
elif y>num:
    print(0)