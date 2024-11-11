N = int(input())
X, Y = [], []
even, odd = 0, 0
for i in range(N):
    x, y = map(int, input().split())
    X.append(x)
    Y.append(y)
    if (x + y) % 2 == 0:
        even += 1
    else:
        odd += 1


def calc(x, y):
    nowx, nowy = 0, 0
    t = ""
    for i in range(30, -1, -1):
        if nowx < x:
            nowx += 2 ** i
            p = 1
        else:
            nowx -= 2 ** i
            p = -1

        if nowy < y:
            nowy += 2 ** i
            q = 1
        else:
            nowy -= 2 ** i
            q = -1

        if p == 1 and q == 1:
            t += "R"
        elif p == 1 and q == -1:
            t += "U"
        elif p == -1 and q == 1:
            t += "D"
        else:
            t += "L"

    return t


if even >= 1 and odd >= 1:
    print(-1)
    exit()

else:
    d = [2 ** i for i in range(30, -1, -1)]
    if even == 0:
        print(30)
        print(" ".join(map(str, d)))
        for i in range(N):
            print(calc(X[i] + Y[i], X[i] - Y[i]))

    else:
        print(31)
        d.append(1)
        print(" ".join(map(str, d)))
        for i in range(N):
            print(calc(X[i] + Y[i] - 1, X[i] - Y[i] - 1) + "R")