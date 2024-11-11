L = int(input())
N = len(bin(L)[2:])
R = 1 << N - 1
UVW = sum([[(i, i+1, 0), (i, i+1, 1<<i-1)] for i in range(1, N)], [])
for i, s in enumerate(bin(L+1)[:2:-1], 1):
    if s == "1":
        UVW.append((i, N, R))
        R += 1 << i - 1

print(N, len(UVW))
for t in UVW:
    print(*t)