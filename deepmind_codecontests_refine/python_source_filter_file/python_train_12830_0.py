for _ in range(int(input())):
    n=int(input())
    lst=[int(i) for i in input().split()]
    lst.sort(reverse=True)
    for i in lst:
        if i<=n:
            break
        else:
            n=n-1
    print(n)    