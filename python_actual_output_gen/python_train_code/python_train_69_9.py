N = input()
K = int(input())

DP = [[[0 for i in range(K+1)] for i in range(2)] for i in range(len(N))]

for d in range(int(N[0])+1):
    DP[0][d<int(N[0])][d!=0] += 1

for i in range(len(N)-1):
    for j in range(2):
        for k in range(K+1):
            for d in range(10 if j else int(N[i+1])+1):
                if k+(d!=0) <= K:
                    DP[i+1][j|(d<int(N[i]))][k+(d!=0)] += DP[i][j][k]

print(DP[len(N)-1][0][K]+DP[len(N)-1][1][K])