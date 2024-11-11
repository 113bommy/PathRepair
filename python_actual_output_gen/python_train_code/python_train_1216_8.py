N = int(input())
C = [0] * N
S = [0] * N
F = [0] * (N - 1)
F.append(1)

for i in range(N - 1):
    C[i], S[i], F[i] = map(int, input().split())

for i in range(N):
    time = S[i]
    for j in range(i, N):
        time = max(abs((time - S[j])) % F[j] + time, S[j]) + C[j]
    print(time)