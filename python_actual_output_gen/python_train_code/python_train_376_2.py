for _ in range(int(input())):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    if k == 1:
        if len(set(arr)) > 1:
            print(-1)
        else:
            print(1)
    else:
        print((len(set(arr))-1+k-2)//(k-1))
