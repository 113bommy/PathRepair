def match(x, y):
    return x == y or x == '?' or y == '?'


def check(s, t):
    ANS = [1] * (10 ** 5)
    S = len(s); T = len(t)
    for i in range(S):
        for j in range(T):
            if not match(s[i], t[j]):
                ANS[i - j + 50000] = 0
    return ANS


def solve(a, b, c):
    lenA = len(a)
    lenB = len(b)
    lenC = len(c)

    AB = check(a, b)
    AC = check(a, c)
    BC = check(b, c)

    ans = lenA + lenB + lenC
    for i in range(-lenB, lenA + lenB + 1):
        for j in range(-lenC, lenA + lenC + 1):
            if AB[i + 50000] and AC[j + 50000] and BC[j - i + 50000]:
                L = min(0, min(i, j))
                R = max(lenA, max(lenB + i, lenC + j))
                ans = min(ans, R - L)

    return ans


a = input()
b = input()
c = input()


ans = min(solve(a, b, c), min(solve(b, c, a), solve(c, a, b)))

print(ans)
