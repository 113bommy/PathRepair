n,m=map(int,input().split())
a=[[int(i) for i in input().split()] for l in range(n)]
b=[[int(i) for i in input().split()] for l in range(m)]
for A in a:
    c=1
    r=0
    m=100000000
    for B in b:
        k=abs(A[0]-B[0])+abs(A[1]-B[1])
        if m>k:
            m=k
            r=c
        c+=1
    print(r)
