def main():
    from math import gcd
    n, l, cache = int(input()), [], {(0, 0): 80400}
    result = n * (n - 1) * (n - 2) // 6
    for _ in range(n):
        cnt = {}
        newx, newy = map(int, input().split())
        for x, y in l:
            x -= newx
            y -= newy
            u = cache.get((x, y))
            if u is None:
                u = gcd(x, y)
                u = cache[x, y] = 80400 + (x * 401 + y) // (u if x > 0 or not x and y > 0 else -u)
            cnt[u] = cnt.get(u, -1) + 1
            result -= cnt[u]
        l.append((newx, newy))
    print(result)


if __name__ == '__main__':
    main()
