import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")

class BitSum:
    def __init__(self, n):
        self.n = n + 3
        self.table = [0] * (self.n + 1)

    def update(self, i, x):
        i += 1
        while i <= self.n:
            self.table[i] += x
            i += i & -i

    def sum(self, i):
        i += 1
        res = 0
        while i > 0:
            res += self.table[i]
            i -= i & -i
        return res

def InversionNumber(lst):
    bit = BitSum(max(lst))
    res = 0
    for i, a in enumerate(lst):
        res += i - bit.sum(a)
        bit.update(a, 1)
    return res

def main():
    s = input()
    n = len(s)
    ord_a = ord("a")
    cnts = [0] * 26
    s_code = []
    flag_odd = False
    for c in s:
        code = ord(c) - ord_a
        s_code.append(code)
        cnts[code] += 1
    odd_code = -1
    for code, cnt in enumerate(cnts):
        if cnt % 2 == 1:
            if flag_odd:
                print(-1)
                exit()
            else:
                odd_code = code
                flag_odd = True
        cnts[code] = cnt // 2
    tois = [[] for _ in range(26)]
    to_sort_idx = []
    new_idx = 1
    for code in s_code:
        if cnts[code] > 0:
            to_sort_idx.append(new_idx)
            tois[code].append(n + 1 - new_idx)
            cnts[code] -= 1
            new_idx += 1
        else:
            if flag_odd and code == odd_code:
                to_sort_idx.append(n // 2 + 1)
                flag_odd=False
            else:
                to_sort_idx.append(tois[code].pop())
    print(to_sort_idx)
    print(InversionNumber(to_sort_idx))

main()
