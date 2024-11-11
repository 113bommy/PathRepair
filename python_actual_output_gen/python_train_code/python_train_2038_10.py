N, K, C = map(int, input().split())
S = input()

L = [0] * K
i = 0
x = 0
while i<K and x<N:
    if S[x] == 'o':
        L[i] = x
        i += 1
        x += C
    else:
        x += 1

R = [0] * K
i = K-1
x = N-1
while i>=0 and x>=0:
    if S[x] == 'o':
        R[i] = x
        i -= 1
        x -= C
    else:
        x -= 1

ans = []
for i in range(K):
    if L[i] == R[i]:
        ans.append(L[i])
for a in ans:
    print(a+1)
