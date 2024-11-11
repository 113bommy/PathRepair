t=int(input())
for i in range(0,t):
    n,m=map(int,input().split())
    l=list(map(int,input().split()))
    x=l[0]
    sum=0
    for j in range(1,len(l)):
        sum=sum+l[j]
    if sum+x>=m:
        print(m)
    else:
        print(sum+x)
