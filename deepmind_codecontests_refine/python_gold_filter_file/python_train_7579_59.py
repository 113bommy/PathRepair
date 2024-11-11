# C

N,K = map(int,input().split())
H = sorted([int(input()) for _ in range(N)])
print(min(H[i+K-1]-H[i] for i in range(N-K+1)))