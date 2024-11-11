from bisect import bisect_left
from sys import stdin


def solve():
    n, m, k = map(int, stdin.readline().split())
    verti_line = list(map(int, stdin.readline().split()))
    hori_line = list(map(int, stdin.readline().split()))
    verti = []  # points in vertical line only
    hori = []
    for _ in range(k):
        x, y = map(int, stdin.readline().split())
        idx1 = bisect_left(verti_line, x)
        idx2 = bisect_left(hori_line, y)
        if verti_line[idx1] == x and hori_line[idx2] == y:
            continue

        elif verti_line[idx1] == x:
            verti.append((idx2, x))
        else:
            hori.append((idx1, y))

    verti = list(sorted(verti))
    hori = list(sorted(hori))

    ans = 0
    # check verti+verti case
    j = 0
    for i in range(1, m + 1):
        if j == len(verti):
            break
        count = 0
        temp = []
        curr_bar = -1
        while j < len(verti) and verti[j][0] == i:
            bar = verti[j][1]
            count += 1
            j += 1
            if bar == curr_bar:
                temp[-1] += 1
            else:
                curr_bar = bar
                temp.append(1)
        ans += count * (count - 1) // 2
        for x in temp:
            ans -= x * (x - 1) // 2

    j = 0
    for i in range(1, n + 1):
        if j == len(hori):
            break
        count = 0
        temp = []
        curr_bar = -1
        while j < len(hori) and hori[j][0] == i:
            bar = hori[j][1]
            count += 1
            j += 1
            if bar == curr_bar:
                temp[-1] += 1
            else:
                curr_bar = bar
                temp.append(1)

        ans += count * (count - 1) // 2
        for x in temp:
            ans -= x * (x - 1) // 2

    print(ans)


t = int(stdin.readline().strip())

for _ in range(t):
    solve()
