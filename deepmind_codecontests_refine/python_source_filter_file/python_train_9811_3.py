from sys import stdin, gettrace
from bisect import bisect

if not gettrace():
    def input():
        return next(stdin)[:-1]


# def input():
#    return stdin.buffer.readline()

def main():
    def solve():
        nr, ng, nb = map(int, input().split())
        rr = [int(a) for a in input().split()]
        gg = [int(a) for a in input().split()]
        bb = [int(a) for a in input().split()]
        rr.sort()
        gg.sort()
        bb.sort()
        best = int(10E20)

        def val(r, g, b):
            return (r - g) ** 2 + (g - b) ** 2 + (b - r) ** 2

        def bri(g, r, bb):
            bi = bisect(bb, (g + r) / 2)
            if bi == 0:
                return val(r, g, bb[0])
            if bi == len(bb):
                return val(r, g, bb[-1])
            else:
                return min(val(r, g, bb[0]), val(r, g, bb[-1]))

        for r in rr:
            gi = bisect(gg, r)
            if gi != 0:
                best = min(bri(gg[gi -1], r, bb), best)
            if gi != ng:
                best = min(bri(gg[gi], r, bb), best)
            bi = bisect(bb, r)
            if bi != 0:
                best = min(bri(bb[bi - 1], r, gg), best)
            if bi != nb:
                best = min(bri(bb[bi], r, gg), best)
        print(best)






    q = int(input())
    for _ in range(q):
        solve()

if __name__ == "__main__":
    main()