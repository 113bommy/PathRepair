n = int(input())
L = sorted(map(int, input().split()))
S = [0] * n
S[0] = L[0]
cnt = 0
for i in range(n-1):
    S[i+1] = S[i] + L[i+1]
    if L[i+1] <= 2 * S[i]:
        cnt += 1
    else:
        cnt = 1
print(cnt)
