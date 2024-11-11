#ABC128 C
N, M = (int(_) for _ in input().split())
A = [list(map(int, input().split()))[1:] for _ in range(M)]
P = list(map(int, input().split()))
ans = 0
for i in range(N):
    for j, S in enumerate(A):
        if P[j] ^ sum(i >> k-1 & 1 for k in S) & 1:
            break
    else:
        ans += 1
print(ans)   