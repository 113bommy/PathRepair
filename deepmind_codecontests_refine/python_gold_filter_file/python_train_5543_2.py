import math

N, K = [int(i) for i in input().split()]

M = sorted([int(i) for i in input().split()], reverse=True)

C = [int(i) for i in input().split()]

G = []
i = len(M) - 1
answer = 0
for k in range(K):
    while i >= 0 and M[i] < k+1:
        i -= 1
    G.append(i+1)
    answer = max(answer, math.ceil(G[k]/C[k]))

test_cases = [[] for k in range(answer)]

for j, m in enumerate(M):
    test_cases[j % answer].append(m)

print(answer)
for test_case in test_cases:
    print(len(test_case), ' '.join([str(e) for e in test_case]))
