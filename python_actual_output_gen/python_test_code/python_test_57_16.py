n=int(input())
if n==1:
    print(-1)
else:
    arr=[int(i) for i in range(n,0,-1)]
    print(*arr)