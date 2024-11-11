# -*- coding: utf-8 -*-
S = list(input())
K = int(input())

for i in range(len(S)-1):
    if S[i] == 'a':
        continue

    d = ord('z') - ord(S[i]) + 1
    if K >= d:
        S[i] = 'a'
        K -= d
    # print(K, d)

if K > 0:
    j = ord(S[-1]) + K
    S[-1] = chr(j)

print(''.join(S))