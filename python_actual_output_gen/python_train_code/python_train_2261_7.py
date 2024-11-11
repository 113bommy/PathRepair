n,x,y=map(int,input().split())
s=input()
a=b=0
for i in s+'1':
    if i=='1':a+=b;b=0
    else:b=1
print(min((a-1)*x+y,a*y))