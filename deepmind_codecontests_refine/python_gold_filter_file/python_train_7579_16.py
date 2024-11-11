N, K = map(int, input().split())
H = [int(input()) for _ in range(N)]

H.sort()

print(min(H[i+K-1] - H[i] for i in range(N-K+1)))