N, K = map(int, input().split())
P = list(map(int, input().split()))

M = [sum(P[:K]) / 2 + K / 2]

for i in range(1, N-K+1):
    M.append(M[i-1] - P[i-1]/2 + P[i]/2)


print(max(M))
