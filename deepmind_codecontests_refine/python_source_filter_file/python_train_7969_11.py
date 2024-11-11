n = int(input())
if(n%2==0):
    if(n == 2):
        print(-1)
    else:
        print((n*n)//(4-1), (n*n)//(4+1))
else:
    if(n==1):
        print(-1)
    else:
        print((n*n-1)//2, (n*n+1)//2)
