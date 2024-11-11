import bisect

N = int(input())
LIS = [-1 * int(input())]
for _ in range(N-1):
    A = -1 * int(input())
    if A >= LIS[-1]:
        LIS.append(A)
    else:
        LIS[bisect.bisect_left(LIS, A)] = A

print(len(LIS))