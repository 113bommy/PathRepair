import math
from itertools import chain, combinations

def powerset(seq):
    if len(seq) <= 1:
        yield seq
        yield []
    else:
        for item in powerset(seq[1:]):
            yield [seq[0]]+item
            yield item

n = list(input())

orign = n

def valid(subset):

    # m = []
    # for i in range(len(subset)):
    #     if subset[i]:
    #         m.append(n[i])
    m = ''.join(subset)
    if len(m) == 0:
        return False
    if subset[0] == '0':
        return False
    if math.sqrt(int(m)) == int(math.sqrt(int(m))):
        return True
    return False


res = []
subsets = list(powerset(n))
print(subsets)
for i in subsets:
    if valid(i):
        res.append(len(n) - len(i))

if len(res) == 0:
    print(-1)
else:
    print(min(res))

# def subsetgen(subset, val, l):
#     subset.append(val)
#     s1 = subset[:]
#     s2 = subset[:]
#     if len(subset) <= len(n):
#         if valid(subset):
#             print(subset)
#             res.append(l - subset.count(True))
#             return True
#         if(len(subset) == len(n)):
#             return False
#     works = subsetgen(s1, True, l)
#     works = works or subsetgen(s2, False, l)
#     return works
#
# subsetgen([], True, len(n))
# subsetgen([], False, len(n))
#
# if len(res) == 0:
#     print(-1)
# else:
#     print(min(res))
#
# print(res)