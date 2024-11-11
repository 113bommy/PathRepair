K = int(input())
S = str(input())

print(S if len(S) <= K else S[:K]+"...")