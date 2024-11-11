from sys import stdin, stdout
from math import sin, tan, cos, pi, atan2, sqrt, acos, atan, factorial


def gcd(a, b):
    if not b:
        return a
    else:
        return gcd(b, a % b)


def solution(la, ra, ta, lb, rb, tb):
    g = gcd(ta, tb)
    d = (lb - la) % g
    return min(ra - la + 1 - d, rb - lb + 1)


la, ra, ta = map(int, stdin.readline().split())
lb, rb, tb = map(int, stdin.readline().split())


ans = max(solution(la, ra, ta, lb, rb, tb), solution(lb, rb, tb, la, ra, ta))
stdout.write(str(ans))