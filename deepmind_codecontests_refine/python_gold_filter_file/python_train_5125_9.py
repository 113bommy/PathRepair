for _ in range(int(input())):
    n, d = map(int, input().split())
    arr = list(map(int, input().split()))
    ans = 0
    for i in range(1, n):
        if d - i < 0:
            break
        while arr[i] > 0 and d - i >= 0:
            d -= i
            ans += 1
            arr[i] -= 1
    print(arr[0] + ans)
