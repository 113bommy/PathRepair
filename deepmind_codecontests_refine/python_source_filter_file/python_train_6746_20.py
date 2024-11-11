from bisect import bisect_left

N = int(input())
A = [int(input()) for _ in range(N)]
A.reverse()

L = [A[0]]
for a in A[1:]:
    if a >= L[-1]:
        L.append(a)
    else:
        L[bisect_left(L, a)] = a

print(len(L))
