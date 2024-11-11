def fill(r, c, result, mapa):
    n = len(result)
    que = [(r, c)]
    for rr, cc, com, comr in [
        (r - 1, c, 'D', 'U'),
        (r + 1, c, 'U', 'D'),
        (r, c - 1, 'R', 'L'),
        (r, c + 1, 'L', 'R')]:
        if 0 <= rr < n and 0 <= cc < n and result[rr][cc] is None and mapa[rr][cc] == -1:
            result[rr][cc] = com
            result[r][c] = comr
            que.append((rr, cc))
            break
    else:
        return False

    index = 0
    while index < len(que):
        r, c = que[index]
        for rr, cc, com in [(r - 1, c, 'D'), (r + 1, c, 'U'), (r, c - 1, 'R'), (r, c + 1, 'L')]:
            if 0 <= rr < n and 0 <= cc < n and result[rr][cc] is None and mapa[rr][cc] == -1:
                result[rr][cc] = com
                que.append((rr, cc))
        index += 1
    return True


def go():
    n = int(input())
    result = [[None] * n for _ in range(n)]
    que = []
    mapa = [[0] * n for _ in range(n)]
    infinites = 0
    count = 0
    for r in range(n):
        vals = list(map(lambda s: int(s) - 1, input().split()))
        x, y = vals[::2], vals[1::2]
        for c in range(n):
            if x[c] == c and y[c] == r:
                result[r][c] = 'X'
                que.append((r, c))
                count += 1
            mapa[r][c] = -1 if x[c] < 0 else (y[c] * n + x[c])
            infinites += x[c] < 0

    index = 0
    while index < len(que):
        r, c = que[index]
        for rr, cc, com in [(r - 1, c, 'D'), (r + 1, c, 'U'), (r, c - 1, 'R'), (r, c + 1, 'L')]:
            if 0 <= rr < n and 0 <= cc < n and result[rr][cc] is None and \
                    mapa[rr][cc] == mapa[r][c]:
                result[rr][cc] = com
                count += 1
                que.append((rr, cc))
        index += 1

    if count + infinites != n * n:
        print('INVALID')
        return

    for r in range(n):
        for c in range(n):
            if result[r][c] is None:
                if mapa[r][c] != -1 or not fill(r, c, result, mapa):
                    print('INVALID')
                    return

    print('VALID')
    print('\n'.join(''.join(r) for r in result))
    # print('\n'.join(''.join(map(str, r)) for r in result))


go()
