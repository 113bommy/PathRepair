import bisect


def solve(H, heights, pref, N):
    pos = bisect.bisect_left(heights, H)
    res = 0
    k1 = H * pos - pref[pos]
    k2 = pref[N] - pref[pos] - H * (N - pos)
    res = min(k1, k2)
    k1 -= res
    k2 -= res
    res *= M
    res += k1 * A
    res += k2 * R
    return res


N, A, R, M = list(map(int, input().split()))
heights = list(map(int, input().split()))

M = min(M, A + R)

heights = sorted(heights)

pref = [0 for i in range(N + 1)]
for i in range(N):
    pref[i + 1] = pref[i] + heights[i]

# total_sum = pref[N]

b1 = pref[N] // N
b2 = b1 + 1
ans = 10 ** 15

s1 = solve(b1, heights, pref, N)
s2 = solve(b2, heights, pref, N)
ans = min([s1, s2, ans])

for i in range(N):
    bi = heights[i]
    ans = min(ans, solve(bi, heights, pref, N))

print(ans)
