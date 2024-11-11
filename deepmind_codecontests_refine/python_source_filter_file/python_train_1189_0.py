def main():
    n, m = map(int, input().split())
    if n - 2 < m < n * 2 + 3:
        res = ['']
        if n < m:
            k = min(n, m // 2)
            res.append('110' * k)
            n -= k
            m -= k * 2
        if n and m:
            k = max(n, m)
            res.append('10' * k)
            m -= k
            n -= k
        if m:
            res.append('1' * m)
        elif n:
            res[0] = '0'
        print(''.join(res))
    else:
        print(-1)


if __name__ == '__main__':
    main()