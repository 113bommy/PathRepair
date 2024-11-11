t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    result=[]
    black=list("B"*m)
    result.append(black)
    result[0][0]="W"
    black=list("B"*m)
    for j in range(n):
        result.append(black)
    for j in result:
        print(*j,sep="")