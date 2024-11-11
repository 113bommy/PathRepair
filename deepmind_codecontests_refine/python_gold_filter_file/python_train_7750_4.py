n,s = input().split()
n=int(n)
s=int(s)
x,y=[],[]
for i in range(n):
    x1,y1=input().split()
    if(int(x1)+(int(y1)/100)>s):
        continue
    x.append(int(x1))
    y.append(int(y1))
x2=len(x)
if(x2==0):
    print(-1)
else:
    y2=min(y)
    if(y2>0):
        print(100-y2)
    else:
        sm=max(y)
        if(sm==y2):
            print(y2)
        else:
            for i in range(x2):
                if(y[i]!=y2 and y[i]<sm):
                    sm=y[i]
            print(100-sm)
