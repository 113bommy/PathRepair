#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code

from itertools import permutations as perm
from math import factorial as fac
def calc(n):
    a = [i + 1 for i in range(n)]
    cnt = 0
    for i in perm(a):
        ok = True
        for idx,j in enumerate(i):
            if idx + 1 == j:
                ok = False
        cnt += 1 if ok else 0
    return cnt


def main():
    c = [calc(i + 1) for i in range(4)]
    print(c)

    n,k = map(int , input().split())
    fa = 1
    ans = 0

    for i in range(k):
        fa = fa * (n - i)

    while k > 0:
        if k == 1:
            ans = ans + 1
        else:
            ans = ans + (fa // fac(k)) * c[k - 1]
            # print((fa // fac(k)))
        k -= 1
        fa //= (n - k)
    print(ans)
    return

if __name__ == "__main__":
    main()