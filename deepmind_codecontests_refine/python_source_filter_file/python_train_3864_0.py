import itertools

n, k = [int(i) for i in input().split()]

kas = [[0,0,0,0],[1,0,0,1],[0,1,1,0]]

mmm = 998244353

def count_k(ka, k, t):
    if t == 0:#00
        return ka[k][0] + ka[k][1] + ka[k][2] + ka[k-1][3]
    if t == 1:#10
        return ka[k-1][0] + ka[k][1] + ka[k-2][2] + ka[k-1][3]
    if t == 2:#01
        return ka[k-1][0] + ka[k-2][1] + ka[k][2] + ka[k-1][3]
    if t == 3:#11
        return ka[k-1][0] + ka[k][1] + ka[k][2] + ka[k][3]

for i in range(1, n):
    if len(kas) < k + 1:
        kas.append([0,0,0,0])
        kas.append([0,0,0,0])
    for kk in range(min(len(kas)-1, k), 1, -1):
        kas[kk] = [count_k(kas, kk, t) % mmm for t in range(4)]

print(sum(kas[k]) if k < len(kas) else 0)
