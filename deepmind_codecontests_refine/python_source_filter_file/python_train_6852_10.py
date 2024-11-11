import math
class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
 
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
 
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i

get_ints = lambda: [int(st) for st in input().split()]
N=int(input())
inarr=get_ints()

sorted_in = sorted(inarr)
print(sorted_in)
comb = N*(N+1) // 2

def binsearch(lft, rgt):
    half = (lft + rgt) // 2
    # print("investigate: lft {} rgt {} half {} value {}".format(lft, rgt, half, sorted_in[half]))
    if lft >= half:
        return half
    summed = 0
    res = 0

    bit = Bit(2*N+1)
    bit.add(N, 1)
    for i, x in enumerate(inarr):
        value = 1 if x >= sorted_in[half] else -1
        summed += value
        # print("summed: {}, bit: {}".format(summed, bit.sum(N + summed)))
        count = bit.sum(N + summed)
        bit.add(N + summed, 1)
        res += count

    # print("num {} cnt {} judge {}".format(sorted_in[half], res, math.ceil(comb/2)))
    if res >= math.ceil(comb/2):
        return binsearch(half, rgt)
    else:
        return binsearch(lft, half)

# print(sorted_in)
res = binsearch(0, N)
# print(res, sorted_in[res])
print(sorted_in[res])
