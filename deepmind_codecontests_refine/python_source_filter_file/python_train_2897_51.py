import collections
N = int(input())
S = []
for _ in range(N):
    S.append(list(input()))
def taikaku(A):
    n = len(A)
    b = True
    for i in range(n):
        for j in range(n):
            if A[j][i] != A[i][j]:
                b = False
                break
        if not b:
            break
    return(b)
ans = 0
for i in range(N):
    if taikaku(S[i:]+S[:i]):
        ans += N
print(ans)