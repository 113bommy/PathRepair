from sys import stdin


def inp():
    return stdin.buffer.readline().rstrip().decode("utf8")


def itg():
    return int(stdin.buffer.readline())


def mpint():
    return map(int, stdin.buffer.readline().split())


# for case in range(itg()):
n, m, k = mpint()
if n + m <= n * m:
    ans = "U"*n + "L"*m
    for i in range(m):
        if i & 1:
            ans += "R" + "U"*(n-1) + "R"
        else:
            ans += "D" * (n - 1)
    ans = ans[:2*n*m]
    print(len(ans))
    print(ans)
elif n == 1:
    print(2*n*m)
    print("L"*(n*m) + "R"*(n*m))
else:
    print(2*n*m)
    print("U"*(n*m) + "D"*(n*m))
