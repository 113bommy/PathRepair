n=int(input())
x=n*[0]
y=n*[0]
for i in range(n):
    x[i],y[i]=[int(i) for i in input().split()]
if n==1:
    print(-1)
else:
    if n==2:
        if x[0]==x[1] or y[0]==y[1]:
            print(-1)
        else:
            print((abs(x[0]-x[1])*(y[0]-y[1])))
    elif n==3 or n==4:
        x.sort()
        y.sort()
        print(abs((max(x)-min(x))*(max(y)-min(y))))
    
