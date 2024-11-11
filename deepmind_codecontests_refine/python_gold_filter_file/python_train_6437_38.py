S = list(input())
lenS = len(S)
S = S + ['.']
K = lenS
i = 0
ps = S[0]
for s in S:
    if s != ps:
        K = min(K, max(i, lenS-i))
        ps = s
    i += 1
print(K)