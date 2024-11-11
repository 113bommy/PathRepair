from collections import defaultdict
N = int(input())
S = input()
countp = defaultdict(int)
counts = defaultdict(int)
prefix = S[:N]
suffix = S[2*N-1:N-1:-1]
for i in range(1 << (N - 1)):
    p1 = ''
    s1 = ''
    p2 = ''
    s2 = ''
    for j in range(N):
        if (1 << j) & i:
            p1 += prefix[j]
            s1 += suffix[j]
        else:
            p2 += prefix[j]
            s2 += suffix[j]
    countp[(p1, p2)] += 1
    countp[(p2, p1)] += 1
    counts[(s1, s2)] += 1
    counts[(s2, s1)] += 1
    

# print(countp, counts)

ans = 0
for k, v in countp.items():
    ans += v * counts[k]

print(ans)