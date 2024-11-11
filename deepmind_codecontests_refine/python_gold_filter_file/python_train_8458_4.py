for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    seen=[]
    for i in range(len(a)):
        if a[i] not in seen:
            seen.append(a[i])
    print(*seen)
