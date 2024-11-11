t=int(input())
for g in range(t):
    n=int(input())
    x=list(map(int,input().split()))
    y=[0]

    for i in range(1,n):
        prev=x[i-1]^y[i-1]
        curr=prev & ~x[i]
        
        y.append(curr)
    print(*y)

