n, k = map(int, input().split())
a = [input() for _ in range(n + 1)]
c = len([_ for _ in a if _ == '?'])
print('Yes' if k == 0 and (a[0] == '0' or a[0] == '?' and (n + 1 - c) % 2 == 1) or k != 0 and (c > 0 and n % 2 == 1 or c == 0 and sum([_ * pow(k, i, 10**9 + 97) for i, _ in enumerate(map(int, a))]) % (10**9 + 97) == 0) else 'No')
