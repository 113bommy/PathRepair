N,K = map(int,input().split())

ans = []
n = (N+1)//2
if N%2==1:
    for i in range(1,n+1):
        a = i
        b = 4*n-2*i
        c = a+b+n-1
        a += K-1
        b += K-1
        c += K-1
        ans.append([a,b,c])
    for i in range(1,n):
        a = n+i
        b = 4*n-1-2*i
        c = a+b+n-1
        a += K-1
        b += K-1
        c += n-1
        ans.append([a,b,c])
else:
    for i in range(1,n+1):
        a = i
        b = 4*n+2-2*i
        c = a+b+n-1
        a += K-1
        b += K-1
        c += K-1
        ans.append([a,b,c])
        a = n+i
        b = 4*n+1-2*i
        c = a+b+n
        a += K-1
        b += K-1
        c += K-1
        ans.append([a,b,c])

if K>n:
    print(-1)
else:
    for a,b,c in ans:
        print(a,b,c)
