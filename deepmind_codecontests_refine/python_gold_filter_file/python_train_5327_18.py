t=int(input())
for _ in range(t):
    n,j,k=input().split()
    n=int(n)
    j=int(j)
    k=int(k)
    f=n-j
    g=n-k
    f=max(f,g)
    print(f+1)
