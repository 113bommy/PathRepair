N=int(input())
x1,x2=list(map(int,input().split()))
x=[]
y=[]
for i in range(0,N):
    m,c=list(map(int,input().split()))
    x.append((m*(x1+0.000001)+c,i))
    y.append((m*(x2-0.000001)+c,i))
x.sort()
y.sort()
a=[]
b=[]
for i in range(N):
    a.append(x[i][1])
    b.append(y[i][1])
if(a==b):
    print("NO")
else:
    print("YES")
