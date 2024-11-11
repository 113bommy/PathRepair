t = int(input())
for j in range(t):
    n, k, d = map(int, input().split())
    arr = list(map(int, input().split()))
    mini = 1e9
    for l in range(n - d + 1):
        d1 = d
        used = set()
        ans = 0
        for i in range(l, d + l):
            if d1 == 0:
                break
            if arr[i] not in used:
                ans += 1
                used.add(arr[i])
            d1 -= 1
        mini = min(mini, ans)
    print(mini)