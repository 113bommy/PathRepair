import sys
from itertools import permutations
from operator import itemgetter

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

INF = 1000

def solve():
    n, m = map(int, input().split())
    str_l = []
    for i in range(n):
        moji = []
        line = input()
        for c in line:
            if c == '*' or c == '#' or c == '&':
                moji.append('*')
            elif ord('0') <= ord(c) <= ord('9'):
                moji.append('1')
            else:
                moji.append('a')
        str_l.append(moji)

    # debug(str_l, locals())
    row_nums = []

    for i in range(n):
        kyori = [get_kyori(str_l[i], '1'),
                 get_kyori(str_l[i], 'a'),
                 get_kyori(str_l[i], '*')]

        row_nums.append(kyori)

    ans = INF
    debug(row_nums, locals())

    for i, j, k in permutations((0,1,2)):
        tmp = 0
        kyori_c = row_nums.copy()
        kyori_c.sort(key=itemgetter(i))
        tmp += kyori_c[0][i]
        kyori_c = kyori_c[1:]
        kyori_c.sort(key=itemgetter(j))
        tmp += kyori_c[0][j]
        kyori_c = kyori_c[1:]
        kyori_c.sort(key=itemgetter(k))
        tmp += kyori_c[0][k]
        ans = min(tmp, ans)

    print(ans)

def get_kyori(str1, c):
    res = INF

    if c in str1:
        i1 = str1.index(c)
        if i1 > len(str1) // 2:
            i1 = len(str1) - i1
        i2 = len(str1) - str1[::-1].index(c)
        if i2 > len(str1) // 2:
            i2 = len(str1) - i2 + 1
        res = min(i1, i2)

    return res

if __name__ == '__main__':
    solve()