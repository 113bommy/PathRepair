from collections import defaultdict


def solve(n, a):
    d_pos = defaultdict(lambda: -1)
    last_zero_pos = -1
    current_sum = 0
    good_count = 0

    for i in range(n):
        d_pos[current_sum] = i
        current_sum += a[i]
        if current_sum in d_pos:
            idx = max(d_pos[current_sum], last_zero_pos)
            last_zero_pos = idx
        else:
            idx = last_zero_pos
        if a[i] == 0:
            last_zero_pos = i
        good_count += (i - idx)
        d_pos[current_sum] = i + 1
        # print(i, i - idx)
    return good_count


# assert solve(4, [2, -1, 1, 2]) == 6
# assert solve(3, [1, 2, -3]) == 5
# assert solve(3, [41, -41, 41]) == 3
# assert solve(4, [5, -3, -2, 5]) == 7
# assert solve(3, [4, 0, 5]) == 2
# assert solve(5, [-2, 0, 1, 1, 3]) == 7

n = int(input())
a = list(map(int, input().split()))
r = solve(n, a)
print(r)