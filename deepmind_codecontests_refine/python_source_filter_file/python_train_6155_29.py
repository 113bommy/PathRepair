n=int(input())
x,y=map(int,input().split())
w=0
k=min(x,y)
m=max(x,y)
w=k-1
w=w+(m-k)
b=0
b=b+(m-1)
b=b+(k-m)
if k<=b:
    print('White')
else:
    print('Black')
