from math import gcd


def solve(la, ra, ta, lb, rb, tb):
    if la > lb:
        la, ra, ta, lb, rb, tb = lb, rb, tb, la, ra, ta
    da = ra-la
    db = rb-lb
    ans = 0
    dist = lb - la
    g = gcd(ta, tb)
    dist %= g
    if dist == 0:
        return min(da+1, db+1)
    la, ra = lb - dist, lb - dist + da
    ans = max(ans, 1+min(rb, ra) - lb)
    ans = max(ans, 1+min(rb, ra+g) - (la+g))
    return ans


def main():
    la, ra, ta = [int(i) for i in input().split()]
    lb, rb, tb = [int(i) for i in input().split()]
    print(solve(la, ra, ta, lb, rb, tb))


main()
