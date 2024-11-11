from sys import stdin
from collections import *
from bisect import *
from operator import itemgetter


def arr_inp(n):
    if n == 1:
        return [int(x) for x in stdin.readline().split()]
    elif n == 2:
        return [float(x) for x in stdin.readline().split()]
    else:
        return list(stdin.readline()[:-1])


def min_arr(arr):
    arr.append(float('inf'))
    for i in range(len(arr) - 1, 0, -1):
        arr[i - 1] = min(arr[i - 1], arr[i])
    return arr


def main():
    n, x = arr_inp(1)
    mem, a, mi, ans, ixs = defaultdict(set), [arr_inp(1) for i in range(n)], defaultdict(list), float(
        'inf'), defaultdict(list)

    for i in range(n):
        mem[a[i][1] - a[i][0] + 1].add((a[i][0], a[i][2]))

    for i in mem.keys():
        mem[i] = sorted(mem[i], key=itemgetter(0, 1))

        for j, k in enumerate(mem[i]):
            if j == 0 or k[0] != ixs[i][-1]:
                ixs[i].append(k[0])
                mi[i].append(k[1])

        mi[i] = min_arr(mi[i])

    # print(mi, mem, ixs)
    for l, r, c in a:
        dur = r - l + 1
        ix = bisect_right(ixs[x - dur], r + 1)

        if ix > 0 and ixs[x - dur][ix - 1] == r + 1:
            ix -= 1
        if ix == len(ixs[x - dur]):
            continue

        ans = min(ans, mi[x - dur][ix - 1] + c)

    print(ans if ans != float('inf') else -1)


if __name__ == '__main__':
    main()
