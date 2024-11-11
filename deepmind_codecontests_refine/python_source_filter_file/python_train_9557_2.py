def solve(n):
    if n < 3:
        print('No')
        return
    d, m = divmod(n, 4)
    l = d * 4
    if m == 3:
        d += 1
        l += 4
    ans = ['{} {}'.format(x, y) for x, y in ((1, 2), (2, 3), (3, 1 + n), (1 + n, 2 + n), (2 + n, 3 + n))]

    if bin(l).count('1') == 1:
        if m == 0:
            print('No')
            return
        if m < 3:
            ans.extend('{} {}'.format(x, y) for x, y in ((1, l), (l, l + 1), (1, l + n + 1), (l + n + 1, l + n)))
            if m == 2:
                ans.extend('{} {}'.format(x, y) for x, y in ((2, l + 2), (l + n + 1, l + n + 2)))
            m = 3

    for i in range(4, l, 4):
        ans.extend('{} {}'.format(x, y) for x, y in (
            (i, i + 1), (i + 1, i + 2), (i + 2, i + 3), (i + 3, i + n),
            (i + 3, i + n + 1), (i + n + 1, i + n + 2), (i + n + 2, i + n + 3)))

    if m == 3:
        for i in range(4, l, 4):
            ans.append('{} {}'.format(1, i))
        print('Yes')
        print('\n'.join(ans))
        return

    min_k = k = l & -l
    prev = 1
    connected = set()
    while k < l:
        if k & l:
            ans.append('{} {}'.format(prev, k))
            connected.add(k)
            prev = k
        k <<= 1

    for i in range(4, l, 4):
        if i in connected:
            continue
        ans.append('{} {}'.format(1, i))

    # print(*ans, sep='\n')
    # print('--')

    ans.append('{} {}'.format(l, min_k))
    ans.append('{} {}'.format(l + n, prev))

    if m >= 1:
        ans.append('{} {}'.format(l + 1, 1))
        ans.append('{} {}'.format(l + 1 + n, prev))
    if m >= 2:
        ans.append('{} {}'.format(l + 2, 1))
        ans.append('{} {}'.format(l + 2 + n, prev + 2))

    assert len(ans) == 2 * n - 1

    print('Yes')
    print('\n'.join(ans))


n = int(input())
solve(n)
