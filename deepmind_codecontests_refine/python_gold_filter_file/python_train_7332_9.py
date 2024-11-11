def main():
    from sys import stdin
    n, s = map(int, input().split())
    l = []
    for w in stdin.read().splitlines():
        x, y, t = map(int, w.split())
        l.append((x * x + y * y, t))
    l.sort()
    for r2, t in l:
        s += t
        if s > 999999:
            print(r2 ** .5)
            return
    print(-1)


if __name__ == '__main__':
    main()