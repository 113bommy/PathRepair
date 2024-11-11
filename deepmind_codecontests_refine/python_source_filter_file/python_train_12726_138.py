t=int(input())
for i in range(t):
    nm=list(map(int,input().strip().split()))
    n=nm[0]
    m=nm[1]
    if n==0:
        print(1)
    elif n==1:
        print(m)
    else:
        print(2*m)