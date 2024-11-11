for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if a[n-1]!=1:
        print("YES")
    else:
        print("NO")