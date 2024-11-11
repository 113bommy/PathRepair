from collections import Counter
from sys import stdin, gettrace

if gettrace():
    inputi = input
else:
    def input():
        return next(stdin)[:-1]


    def inputi():
        return stdin.buffer.readline()


def solve():
    n = int(inputi())
    aa = [int(a) for a in inputi().split()]
    aac = Counter(aa)
    res = 0
    for a in aac.keys():
        c0, c1, c2 = aac[a], aac[a+1], aac[a+2]
        if c0 >= 3:
            res += (c0 * (c0-1) * (c0-2))//6
        if c0 >= 2 and c1 >= 1:
            res += (c0 * (c0 -1) * c1)//2
        if c0 >= 1 and c1 >= 2:
            res += (c0 + c1 * (c1-1))//2
        if c0 >= 2 and c2 >= 1:
            res += (c0 * (c0 -1) * c2)//2
        if c0 >= 1 and c2 >= 2:
            res += (c0 + c2 * (c2-1))//2
        if c0>=1 and c1>=1 and c2>= 1:
            res += c0*c1*c2
    print(res)




def main():
    t = int(inputi())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
