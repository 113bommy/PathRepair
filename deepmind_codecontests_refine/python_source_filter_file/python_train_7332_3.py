def main():
    from sys import stdin
    n, x = map(int, input().split())
    l = []
    for s in stdin.read().splitlines():
        x, y, t = map(int, s.split())
        l.append((x * x + y * y, t))
    l.sort()
    for r2, t in l:
        x += t
        if x > 999999:
            print(r2 ** .5)
            return
    print(-1)


if __name__ == '__main__':
    main()
