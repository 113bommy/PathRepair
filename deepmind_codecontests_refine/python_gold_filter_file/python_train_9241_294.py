K = int(input())
S = input()
print(S[0:K] + "..." if len(S) > K else S)