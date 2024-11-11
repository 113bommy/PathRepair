N, K = map(int, input().split())
S = input()

print(S[0:K-2]+S[K-1].lower()+S[K:N-1])
