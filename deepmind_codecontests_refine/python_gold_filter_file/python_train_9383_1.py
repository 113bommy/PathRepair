from itertools import accumulate

n, k, m = [int(x) for x in input().split(' ')]
a = sorted([int(x) for x in input().split(' ')])
a_sum = sum(a)
pref_a = [0] + list(accumulate(a))


def score(rem):
    total = len(a) - rem
    return ((a_sum - pref_a[rem]) + min(total * k, m - rem)) / total


print(max(map(score, range(min(m + 1, len(a))))))
