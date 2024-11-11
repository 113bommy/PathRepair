import collections
import itertools
N = int(input())
#cnt[URLD][x y y+x y-x][value]=set()
cnt = [[collections.defaultdict(set) for _ in range(4)] for _ in range(4)]
for _ in range(N):
    x, y, u = input().split()
    x = int(x)
    y = int(y)
    p = y + x
    q = y - x
    i = 'URLD'.index(u)
    cnt[i][0][x].add(y)
    cnt[i][1][y].add(x)
    cnt[i][2][p].add(q)
    cnt[i][3][q].add(p)

INF = float('inf')


def calc(up, down):
    ret = [INF]
    for c in up.keys() & down.keys():
        ua = sorted(up[c])
        da = sorted(down[c])
        i = j = 0
        for i in range(len(ua)):
            for j in range(j, len(da)):
                if ua[i] < da[j]:
                    ret += [da[i] - ua[i]]
                    break
            i += 1
    return min(ret)


#U(0)とD(3)がx(0)が一緒:d-u(>=0)の最小値
#R(1)とL(2)がy(1)が一緒:l-r(>=0)の最小値
#U(0)とR(1)がx+y(2)が一緒:(y-x)のr-u(>=0)の最小値
#L(2)とD(3)がx+y(2)が一緒:(y-x)のd-l(>=0)の最小値
#U(0)とL(2)がy-x(3)が一緒:(y+x)のl-u(>=0)の最小値
#R(1)とD(3)がy-x(3)が一緒:(y+x)のd-r(>=0)の最小値
ans = min(
    calc(cnt[0][0], cnt[3][0]), calc(cnt[1][1], cnt[2][1]),
    calc(cnt[0][2], cnt[1][2]), calc(cnt[2][2], cnt[3][2]),
    calc(cnt[0][3], cnt[2][3]), calc(cnt[1][3], cnt[3][3]))
print('SAFE' if ans == INF else ans * 5)
