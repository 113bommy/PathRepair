l = int(input())
x = list(map(int,input().split()))
x1=x.copy()
x1.sort()
for i in range(1,len(x)):
    x[i]=x[i]+x[i-1]
    x1[i]=x1[i]+x1[i-1]

c = int(input())
for _ in range(c):
    f,i,j=map(int,input().split())
    if(f==1):
        if(i==1):
            print(x[j-1])
        else:
            print(x[j-1]-x[i-1-1])
    else:
        if(i==1):
            print(x1[j-1])
        else:
            print(x1[j-1]-x1[i-1-1])
