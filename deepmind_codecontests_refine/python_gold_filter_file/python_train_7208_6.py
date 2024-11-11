t=int(input())
for i in range(t):
    n,m,k=map(int,input().split())
    q=n//k
    if q>=m:
        print(int(m))
    else:
        r=(m-q)/(k-1)
        if r%1==0:
            print(int(q-r))
        else:
            print(q-int(r)-1)
            