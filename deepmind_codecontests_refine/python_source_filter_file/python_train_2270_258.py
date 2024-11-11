N, K = map(int,input().split())
S = input()

s = S[:K-2] + S[K-1].lower() + S[K:]

print(s)

