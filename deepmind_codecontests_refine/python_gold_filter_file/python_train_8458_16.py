t=int(input())
for o in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=[]
    for i in range(2*n):
        if a[i] not in b:
            b.append(a[i])
    print(*b)