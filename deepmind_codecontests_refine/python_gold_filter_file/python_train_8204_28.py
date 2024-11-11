N = int(input())
S = list(input())
ma=0
for i in range(N-1):
    ma=max(len(set(S[:i]) & set(S[i:])), ma)
print(ma)