K = int(input())
S = input()

print(S[:K]+'...' if len(S)>int(K) else S)