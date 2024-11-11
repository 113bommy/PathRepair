import sys
from heapq import *
def input(): return sys.stdin.readline().strip()


def func(left):
    ll = len(left)
    """
    前から順番に詰めていく方式だと次の反例が存在する：
    ll = 2, left = [(1, 1), (2, 2), (3, 100)]
    (3, 100)をなるべく先頭に置くべきだが、前のコードだと３番目が車で保留。
    ll < 3なのでその時は訪れない。

    なのでやはり後ろから攻めるしかない模様。
    """
    L = [[] for _ in range(ll + 1)]
    for k, v in left:
        if k > ll: k = ll
        L[k].append(v)
    ans = 0
    q = []
    for i in range(ll, 0, -1):
        for v in L[i]: heappush(q, v)
        if q: ans += heappop(q)
    return ans


def main():
    T = int(input())
    for _ in range(T):
        n = int(input())
        ans = 0
        left = []
        right = []
        for _ in range(n):
            k, l, r = map(int, input().split())
            if l > r:
                ans += r
                left.append((k, l - r))
            else:
                ans += l
                right.append((n - k, r - l))
        #print("left={}".format(left))
        #print("right={}".format(right))
        ans += func(left)
        ans += func(right)
        print(ans)


if __name__ == "__main__":
    main()
