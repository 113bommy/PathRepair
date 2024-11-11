N, K = map(int, input().split())
S = input()
print(S[:K]+S[K].lower()+S[K+1:])