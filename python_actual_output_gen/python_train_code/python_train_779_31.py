def rii():
    return [int(x) for x in input().split()]


n, m = rii()

ans = float("inf")
for a in range(n):
    b = (n - a) / 2
    if a + 2 * b == float(n) and ((a + b) % m) == 0:
        # print(a, b)
        ans = min(ans, int(a + b))
print(ans if ans != float("inf") else -1)
