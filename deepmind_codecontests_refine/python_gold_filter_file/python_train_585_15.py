import math

k, d, t = list(map(int, input().split()))
if k % d == 0:
    print(t)
else:
    m = math.ceil(k / d) * d
    if 2 * t % (m + k) == 0:
        print(m * 2 * t / (m + k))
    else:
        n = math.floor(2 * t / (m + k))
        ans = n * m
        f = 1 - (m  + k) * n / (2 * t)
        if f <= k / t:
            print(ans + f * t)
        else:
            ans += k
            f -= k / t
            print(ans + f * 2 * t)

