n=int(input())
p=list(map(int,input().split()))
for i in range(1,n+1):
    for j in range(n):
        if(p[j]==i):
            print(i+1,end=" ")