import sys
readline = sys.stdin.readline

S = tuple(map(ord, readline().strip()))
N = len(S)
Ans = [0]*N
pre = S[0]
for i in range(1, N-1): 
    if pre <= S[i]:
        Ans[i] = 1
    pre = min(pre, S[i])
print(*['Ann' if a else 'Mike' for a in Ans], sep = '\n')
