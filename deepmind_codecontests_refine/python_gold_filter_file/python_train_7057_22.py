from itertools import groupby

S = input()
K = int(input())

A = [len(tuple(v)) for _, v in groupby(S)]
if len(A) == 1:
    print((A[0] * K) // 2)
    quit()

if S[0] == S[-1]:
    m = sum(a // 2 for a in A) - A[0] // 2 - A[-1] // 2
    print(K * m + (K - 1) * ((A[0] + A[-1]) // 2) + A[0] // 2 + A[-1] // 2)
else:
    print(sum(a // 2 for a in A) * K)
