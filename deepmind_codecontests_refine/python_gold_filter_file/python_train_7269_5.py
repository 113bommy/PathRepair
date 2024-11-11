n,y=map(int,input().split())

for i in range(n+1):
    for j in range(n+1-i):
        x=n-i-j
        if 1000*i+5000*j+10000*x==y:
            print(x,j,i)
            exit()
print(-1,-1,-1)
