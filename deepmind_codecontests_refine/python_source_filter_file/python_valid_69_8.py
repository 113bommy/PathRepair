pat = []
for i in range(40):
    pat.append(1 << i)

T = int(input())

def solve(x, y):
    x, y = str(x), str(y)
    ans, i = 0, 0
    for c in y:
        while i < len(x) and x[i] != c:
            i += 1
        if i < len(x):
            ans += 1
            i += 1
        else:
            break
    return len(x) + len(y) - 2 * ans

for t in range(T):
    n = int(input())
    ans = min(solve(n, k) for k in pat)
    print(ans)
