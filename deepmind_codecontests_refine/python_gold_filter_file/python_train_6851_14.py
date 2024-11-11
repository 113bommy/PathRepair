#https://atcoder.jp/contests/yahoo-procon2019-qual/tasks/yahoo_procon2019_qual_d
#2019-02-10

#DP

L = int(input())
A = [int(input()) for i in range(L)]

DP = [[float("inf") for i in range(5)] for j in range(L+1)]
for i in range(5):
    DP[0][i] = 0

def cost(s, i, A):
    if s == 0 or s == 4:
        return A[i]
    elif s == 1 or s == 3:
        if A[i] > 0:
            if A[i]%2 == 0:
                return 0
            else:
                return 1
        else:
            return 2
    else:
        if A[i]%2 == 1:
            return 0
        else:
            return 1

for i in range(L):
    for j in range(5):
        for k in range(j,5):
            DP[i+1][k] = min(DP[i+1][k], DP[i][j]+ cost(k, i, A))



print(min(DP[L]))