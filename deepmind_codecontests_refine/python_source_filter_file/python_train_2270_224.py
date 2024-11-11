N,K = map(int,input().split())
S = input()
print(S[:k-1] + S[K-1].lower() + S[k-2:])
