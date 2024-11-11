n=int(input())
x=[]
y=[]
for i in range(n):
    a,b=map(int,input().split())
    x.append(a)
    y.append(b)
f=0
count=0
def ch(x,y):
    if sum(x)%2==0:
        if sum(y)%2==0:
            return 1
    else:
        return 0
if ch(x,y):
    print(0)

else:
    f=0
    for i in range(n):
        f=0
        x[i],y[i]=y[i],x[i]
        count+=1
        if ch(x,y) :
            print(count)
            f=1
            break
        else:
            continue
    if f==0:
        print(-1)