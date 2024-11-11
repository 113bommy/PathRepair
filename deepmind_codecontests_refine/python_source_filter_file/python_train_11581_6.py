from sys import stdin


def inp():
    return stdin.buffer.readline().rstrip().decode("utf8")


def itg():
    return int(stdin.buffer.readline())


def mpint():
    return map(int, stdin.buffer.readline().split())


def longest_prefix(a):
    a = a + "#" + a[::-1]
    pref = [0] * len(a)
    c = 0
    for i in range(1, len(a)):
        while c > 0 and a[c] != a[i]:
            c = pref[c - 1]
        if a[c] == a[i]:
            c += 1
        pref[i] = c

    return a[:c]

# for case in range(itg()):
for case in range(itg()):
    s = inp()
    n = len(s)

    k = 0
    for i in range(n >> 1):
        if s[i] == s[-i - 1]:
            k = i + 1
        else:
            break
    prefix = s[:k]
    suffix = s[:k][::-1]
    if k:
        s = s[k: -k]

    mid = max(longest_prefix(s), longest_prefix(s[::-1]), key=max)

    print(prefix + mid + suffix)