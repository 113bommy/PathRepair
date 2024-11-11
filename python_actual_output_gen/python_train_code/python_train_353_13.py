x,y=map(int,input().split())
p,q=map(int,input().split())
for i in range(0,101):
    for j in range(0,101):
        if (y+(i-1)*x)==(q+(j-1)*p):
            print(y+(i-1)*x)
            exit()
print(-1)