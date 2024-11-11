N, K, C = map(int, input().split())
S = input()
L, R = [0]*N, [0]*N
i = 0
count = 1
while count <= K:
    if S[i] == 'x':
        i += 1
        continue
    L[i] = count
    count += 1
    i += C+1
i = N-1
count = K
while count > 0:
    if S[i] == 'x':
        i -= 1
        continue
    R[i] = count
    count -= 1
    i -= C+1
for i in range(N):
    if L[i] == 0:
        continue
    if L[i] == R[i]:
        print(i+1)