# encoding: utf-8
L = int(input())

# length
for l_max in range(1, 20):
    if 2 ** l_max > L: break

# encode L - 2 ** (l_max - 1)
bits_sub = [None] * l_max
L_temp = L - 2 ** (l_max - 1)
for l in range(l_max):
    bits_sub[l] = L_temp % 2
    L_temp = L_temp // 2

# result
N = l_max
M = 2 * (l_max - 1) + sum(bits_sub)
print(N, M) # oh...

# main path
for i in range(l_max - 1):
    for j in range(2):
        print(i + 1, i + 2, j * (2 ** i))

# sub path
maxlen = 2 ** (l_max - 1)
for i, bit in enumerate(bits_sub):
    if bit == 0: continue
    for j in range(bit):
        print(i + 1, l_max, maxlen)
        maxlen += 2 ** i