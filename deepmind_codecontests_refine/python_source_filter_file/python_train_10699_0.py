import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    def calc():
        n = int(readline())
        a = list(map(int, readline().split()))
        s = input()
        b = [-1] * 61

        for i in range(n - 1, -1, -1):
            x = a[i]
            if s[i] == "0":
                l = x.bit_length()
                if b[l - 1] == -1:
                    b[l - 1] = x
                else:
                    while b[l - 1] != -1 and x > 0:
                        x ^= b[l - 1]
                        l = x.bit_length()
                    if x != 0:
                        b[l - 1] = x
            else:
                xb = format(x, "b")[::-1]
                l = len(xb)
                cur = 0
                for j in range(l - 1, -1, -1):
                    bit = int(xb[j])
                    cur_bit = int(format(cur,"b").zfill(l)[::-1])
                    if bit ^ cur_bit == 1:
                        if b[j] != -1:
                            cur ^= b[j]
                        else:
                            return print(1)
        return print(0)

    t = int(readline())
    for _ in range(t):
        calc()


if __name__ == '__main__':
    main()
