input()
S = input()
K = int(input())

for s in S:print(s if s==S[K-1] else "*", end="")