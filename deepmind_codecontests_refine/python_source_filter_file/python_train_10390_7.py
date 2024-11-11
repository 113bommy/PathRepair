import math

# input
#
# n = 5
# k = 10
# a = [1, 2, 3, 2, 3]

n, k = map(int, input().split())
a = [int(ai) for ai in input().split()]

# make jumpto
#
# 0 -> 6 (5)
# 1 -> 4 (2)
# 2 -> 5 (2)
# 3 -> 7 (3)
# 4 -> 8 (3)

jumpto = [[-1] * n]
la = -1
li = -1
for (ca, ci) in sorted(zip(a, range(n))):
    if ca == la:
        jumpto[0][ci] = jumpto[0][li] + li - ci
        jumpto[0][li] = ci - li
    else:
        jumpto[0][ci] = n
    la = ca
    li = ci

# doubling jumpto
#
# 0 -> 6 ->  9 (8)
# 1 -> 4 ->  8 (6)
# 2 -> 5 -> 11 (8)
# 3 -> 7 -> 10 (6)
# 4 -> 8 -> 12 (7)
#
# 0 -> 6 ->  9 -> 13 -> 17  (16)
# 1 -> 4 ->  8 -> 12 -> 15  (13)
# 2 -> 5 -> 11 -> 14 -> 18  (15)
# 3 -> 7 -> 10 -> 16 -> 19  (15)
# 4 -> 8 -> 12 -> 15 -> 21  (16)

levels = int(math.log2(k))
for l in range(1, levels + 1):
    jumpto.append([-1] * n)
    for i in range(n):
        f = jumpto[l - 1][i]
        s = jumpto[l - 1][(i + f + 1) % n]
        jumpto[l][i] = f + 1 + s

# step1
s = 0
while True:
    jumped = False
    for l in range(levels, -1, -1):
        if s + jumpto[l][s % n] < n * k:
            s += jumpto[l][s % n] + 1
            jumped = True
            break
    if not jumped:
        break

# step2
ret = []
while s < n * k:
    if s + jumpto[0][s % n] < n * k:
        s = s + jumpto[0][s % n] + 1
    else:
        ret.append(str(a[s % n]))
        s += 1

print(' '.join(ret))
