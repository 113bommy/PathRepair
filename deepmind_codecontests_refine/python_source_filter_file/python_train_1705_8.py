def solve(n,m):
    a=min(n+1,m+1)
    print(a)
    for i in range(a):
        print(i,a-i)





A=list(map(int,input().split()))
solve(A[0],A[1])
