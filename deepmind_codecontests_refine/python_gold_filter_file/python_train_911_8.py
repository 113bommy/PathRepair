import sys


def solve(n, ppp):
    n2 = n + 2
    nsq = n2 * n2
    seats = [0] * nsq
    is_seated = [0] * nsq
    for i in range(n):
        ud = min(i, n - 1 - i)
        ri = (i + 1) * n2
        for j in range(n):
            ij = ri + j + 1
            seats[ij] = min(ud, j, n - 1 - j)
            is_seated[ij] = 1

    MOVES = [-n2, -1, 1, n2]

    ans = 0

    for p in ppp:
        i, j = divmod(p - 1, n)
        i = (i + 1) * n2 + j + 1
        res = seats[i]
        ans += res
        is_seated[i] = 0

        q = []
        for di in MOVES:
            ni = i + di
            if seats[ni] > res:
                seats[ni] = res
                q.append(ni)

        while q:
            j = q.pop()
            val = seats[j]

            if is_seated[j]:
                val += 1
            for dj in MOVES:
                nj = j + dj
                if seats[nj] > val:
                    seats[nj] = val
                    q.append(nj)

    return ans


n, *ppp = map(int, sys.stdin.buffer.read().split())

print(solve(n, ppp))
