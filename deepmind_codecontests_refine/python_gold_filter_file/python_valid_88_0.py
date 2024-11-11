def main():
    test = int(input())
    from collections import defaultdict

    for _ in range(test):
        n, m = map(int, input().split())
        a = list(map(int, input().split()))
        b = sorted(a)
        idx = defaultdict(list)
        seq = defaultdict(list)
        step = defaultdict(int)
        for i in range(n * m):
            x, y = i // m, i % m
            idx[b[i]].append([x, y])
        for i in idx:
            idx[i].sort()
            if idx[i][0][0] < idx[i][-1][0]:
                row = idx[i][0][0]
                t = []
                j = 0
                while j < len(idx[i]):
                    if idx[i][j][0] != row:
                        t.sort(key=lambda x: -x[1])
                        seq[i].extend(t)
                        t = [idx[i][j]]
                        row = idx[i][j][0]
                    else:
                        t.append(idx[i][j])
                    j += 1
                t.sort(key=lambda x: -x[1])
                seq[i].extend(t)
            else:
                idx[i].sort(key=lambda x: -x[1])
                seq[i].extend(idx[i])
            step[i] = 0

        ans = 0
        seat = [[0] * m for _ in range(n)]
        for i, c in enumerate(a):
            x, y = seq[c][step[c]]
            step[c] += 1

            for j in range(y):
                ans += seat[x][j]
            seat[x][y] = 1
        print(ans)

    return


main()


