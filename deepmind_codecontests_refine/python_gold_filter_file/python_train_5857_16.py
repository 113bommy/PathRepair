for __ in range(int(input())):
    a, b = list(map(int, input().split()))
    num = min(a - 1, b)
    ans = num * (num + 1) // 2
    if a - 1 < b:
        ans += 1
    print(ans)