from bisect import bisect_left
from sys import stdin, gettrace

if gettrace():
    def inputi():
        return input()
else:
    def input():
        return next(stdin)[:-1]


    def inputi():
        return stdin.buffer.readline()

MOD = 998244353

def solve():
    n = int(input())
    xys = [[int(a) for a in input().split()] for _ in range(n)]
    vs = [0]
    xx,_,_ = list(zip(*xys))
    res = xx[-1]+1
    for x,y,s in xys:
        si = bisect_left(xx, y)
        v = ((x-y) + vs[-1] - vs[si])%MOD
        vs.append((vs[-1] + v)%MOD)
        if s == 1:
            res = (v+res)%MOD
    print(res)





def main():
    solve()


if __name__ == "__main__":
    main()
