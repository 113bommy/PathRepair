def getCnt(x, len):
    return x * (x - 1) // 2 + x * (2 ** len - 1)

n = int(input())

ans = []

for LEN in range(0, 60):
    l, r = 0, int(1e18)
    while(r - l > 1):
        mid = (l + r) // 2
        if(getCnt(2 * mid + 1, LEN) <= n):
            l = mid
        else:
            r = mid
    if(getCnt(2 * l + 1, LEN) == n):
        x = 2 * l + 1
        ans.append(x * (2 ** LEN))

if(len(ans) == 0):
    print(-1)
else:
    print("\n".join(list(map(str, ans))))