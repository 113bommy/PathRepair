def matrixChainMultiplication(p):
    # p = [p_0, p_1, ..., p_n]
    n = len(p) - 1
    # n+1 x n+1 zero matrix?????????(0,...,n)
    # cost(i,j): (M_i...M_j)???????°??????????
    cost = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    for numOfMatrices in range(2, n + 1):
        for i in range(1, n - numOfMatrices + 2):
            j = i + numOfMatrices - 1
            cost[i][j] = float('inf')
            for k in range(i, j):
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k + 1][j] + p[i - 1] * p[k] * p[j])
    print(m[1][n])

p = []
n = int(input())

for _ in range(n):
    listed_input = input().split()
    p.append(int(listed_input[0]))
p.append(int(listed_input[1]))

matrixChainMultiplication(p)