
n = int(input())
a = list(map(int, input().split(" ")))


def solve(s1, s2):
    "if start == true, assume the first of the sum is positive."
    res = 0
    sum = 0
    for i in range(n):
        sum += a[i]
        if sum <= 0 and i % 2 == s1:
            res += abs(sum) + 1
            sum = 1
        elif sum >= 0 and i % 2 == s2:
            res += abs(sum) + 1
            sum = -1
    return res


print(min(solve(0, 1), solve(1, 2)))
