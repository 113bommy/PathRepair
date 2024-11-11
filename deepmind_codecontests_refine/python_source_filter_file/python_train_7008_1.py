#
#   author : @Imtiaz Adar [Thinker]
#

from  math import gcd
def main():
    n = int(input())
    for i in range(n):
        y = int(input())
        res = 0
        lcmm = 1
        j = 2
        stat = True
        while stat:
            if lcmm > y:
                stat = False
            else:
                L = y // lcmm
                lcmm  = (lcmm // gcd(j, lcmm)) * j
                R = y // lcmm
                v = ((L - R) * j) % mod
                res = (res + v) % mod
            j += 1
        print(res)


if __name__ == '__main__':
    mod = 10000000007
    main()