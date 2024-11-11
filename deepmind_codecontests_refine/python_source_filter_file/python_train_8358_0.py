#1800
import sys
input = sys.stdin.readline
getint = lambda: int(input())
getints = lambda: [int(a) for a in input().split()]

def calc_gcd(big, small):
    if small == 0:
        return big
    return calc_gcd(small, big % small)

def solve():
    n, k = getints()
    x = getints()

    a = min(x)
    gcd = x[0] - a
    if gcd == 0:
        gcd = x[1] - 1
    for xvalue in x:
        if xvalue == a:
            continue
        comparer = gcd, xvalue - a
        gcd = calc_gcd(max(comparer), min(comparer))

    k -= a
    if k % gcd == 0:
        print("YES")
    else:
        print("NO")
    

if __name__ == '__main__':
    t = getint()
    for i in range(t):
        solve()