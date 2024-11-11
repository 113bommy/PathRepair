def main():
    n = int(input())
    ss, xs, ys = [], [], []
    for _ in range(n):
        s, x, y = input().split()
        ss.append(s)
        xs.append(int(x))
        ys.append(int(y))

    res = 0
    for d in range(min(xs), max(ys)):
        f, m = 0, 0
        for i in range(n):
            s, x, y = ss[i], xs[i], ys[i]
            if x <= d <= y:
                if s == 'M':
                    m += 1
                else:
                    f += 1
        res = max(res, min(f, m))

    print(res * 2)

if __name__ == '__main__':
    main()
