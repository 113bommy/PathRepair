t=int(input())
for _ in range(t):
    #n=int(input())
    n,m=map(int,input().split())
    x=list(map(int,input().split()))
    if(sum(x)>=m):
        print(m)
    elif(sum(x)<m):
        print(sum(x))