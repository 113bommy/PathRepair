def solve(values):
    n = len(values)

    ones = []
    twos = []
    for pos, v in enumerate(values):
        if v == '1':
            ones.append(pos)
        else:
            twos.append(pos)

    if not (len(twos) == 0 or len(twos) > 2):
        return None

    ans = [['='] * n for _ in range(n)]
    for x in range(n):
        ans[x][x] = 'X'

    for r in range(len(twos) - 1):
        o = twos[r]
        v = twos[r + 1]
        ans[o][v] = '+'
        ans[v][o] = '-'

    if twos:
        r = twos[-1]
        v = twos[0]
        ans[r][v] = '+'
        ans[v][r] = '-'

    return ans


if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        values = str(input())
        ans = solve(values)

        if ans:
            print("YES")
            for row in ans:
                print(''.join(row))
        else:
            print("NO")
