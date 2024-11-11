n = int(input())
lis = list(map(int,input().split()))
if n>=2:
    print(1,1)
    print(-lis[0])
    print(2,n)
    print(*[(lis[i]*(n-1)) for i in range(1,n)])
    print(1,n)
    print(0,*[-(lis[i]*(n))for i in range(1,n)])
else:
    print(1,1)
    print(-lis[0])
    print(1,1)
    print(0)
    print(1,1)
    print(0)




