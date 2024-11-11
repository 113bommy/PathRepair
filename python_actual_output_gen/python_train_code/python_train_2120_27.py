n=int(input())
x,y=map(int,input().split())
w=0
k=min(x,y)
m=max(x,y)
w=k-1
w=w+(m-k)
b=0
b=b+(n-m)
b=b+abs(k-m)
if (w+1)<=b:
    print('White')
else:
    print('Black')
