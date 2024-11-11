def main():
    N = int(input())
    Tn = tuple(map(int, input().split()))
    Vn = tuple(map(int, input().split()))

    t = (0,) + Tn + (0,)
    v = (0,) + Vn + (0,)
    maxv = [0]
    for i in range(1, N + 1):
        if v[i-1] < v[i] > v[i+1]:
            maxv += [v[i]] * (t[i] * 2 - 1)
        elif v[i-1] > v[i] < v[i+1]:
            maxv += [v[i]] * (t[i] * 2 + 1)
        else:
            maxv += [v[i]] * t[i] * 2
    maxv += [0]

    cnt = len(maxv)
    for i in range(1, cnt):
        maxv[i] = min(maxv[i], maxv[i-1] + 0.5)

    for i in range(cnt - 2, -1, -1):
        maxv[i] = min(maxv[i], maxv[i+1] + 0.5)

    s = 0
    for i in range(cnt - 1):
        s += (maxv[i] + maxv[i+1]) * 0.5 / 2
    print(s)

main()
