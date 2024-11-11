for j in range(int(input())):
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    arr.sort()
    rem = k
    ans = 0
    while (rem > 0):
        ma = max(arr)
        cnt = arr.count(ma)
        if (cnt > rem):
            ans += 1
            arr.pop()
            arr.pop()
        else:
            ind = arr.index(ma)
            ans += 0
            arr.pop(ind - 1)
            arr.pop()
        rem -= 1
    ans += sum(arr)
    print(ans)
