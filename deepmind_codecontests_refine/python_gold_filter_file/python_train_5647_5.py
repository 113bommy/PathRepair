t=int(input())
for _ in range(t):
    n,m=map(int,input().split())

    for i in range(0,n):
        for j in range(0,m):
            if(i==n-1 and j==m-1):
                print('W',end="")
            else:
                print('B',end="")
        print()
