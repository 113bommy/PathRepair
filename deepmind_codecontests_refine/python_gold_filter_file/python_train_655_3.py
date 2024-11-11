for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    s = sum(l)
    if s<=n:
        print(s*(n-s))
    elif s%n==0:
        print(0)
    else:
        print((s%n)*(n-(s%n)))