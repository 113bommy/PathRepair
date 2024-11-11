t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    n1=n
    if n%2!=0:
        j=3
        while(j*j<=n1):
            if n1%j==0:
                n1=n1+j
                k=k-1
                break
            j=j+2
        if n1==n:
          n1=n1+n1
          k=k-1
    print(n1+(2*k))