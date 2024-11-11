for _ in range(int(input())):
    n=int(input())
    a=list(map(int, input().split()))
    if a[0] - sum(-min(a[i] - a[i-1], 0) for i in range(1,n)) >= 0:
        print("YES")
    else: print("NO")