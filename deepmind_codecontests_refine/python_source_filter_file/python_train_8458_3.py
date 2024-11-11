for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    seen=set()
    for i in range(len(a)):
        if a[i] not in seen:
            seen.add(a[i])
    print(*seen)
