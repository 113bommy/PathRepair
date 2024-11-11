def iter_bit(k, LIMIT):
    v = (1 << k) - 1

    while v < LIMIT:
        yield v
        x = v & -v
        y = v + x
        v = (v & ~y) // x >> 1 | y


def solve(n, cards):
    dp = [{} for _ in range(1 << n)]
    dp[-1][0] = 0
    LIMIT = 1 << n

    for d in range(n):
        for state in iter_bit(n - d, LIMIT):
            scores = dp[state]
            k = state
            curr = 0
            while k:
                b = k & -k
                i = b.bit_length() - 1
                num = cards[i][(d - i) % 2]
                next_dp = dp[state ^ b]
                for left_num, score in scores.items():
                    if left_num > num:
                        continue
                    ns = score + curr
                    if num not in next_dp or next_dp[num] > ns:
                        next_dp[num] = ns
                k ^= b
                curr += 1

    if len(dp[0]) > 0:
        return min(dp[0].values())
    else:
        return -1


n = int(input())
aaa = list(map(int, input().split()))
bbb = list(map(int, input().split()))
cards = list(zip(aaa, bbb))
print(solve(n, cards))
