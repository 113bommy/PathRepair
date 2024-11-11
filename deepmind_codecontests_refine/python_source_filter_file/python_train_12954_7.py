n,m = map(int,input().split())

if m<n//2 and n!=1 or (n==1 and m>=n) :
    print(-1)

else:
    if m:
        k = (n-2)//2
        print((m-k),end=" ")
        print((m-k)*2,end=" ")
        n-=2
        c = (m-k)*2+1

    if n and n!=1:
        for i in range(c,c+n):
            print(i,end=" ")
    else:
        print(1)

