import sys
n, k = [int(i) for i in sys.stdin.readline().split()]
a_ls = [int(i) for i in sys.stdin.readline().split()]
memo_ls = [[0 for i in range(k+1)] for j in range(n)]
memo_ls[0][0] = 1
for i in range(n):
    for j in range(k+1):
        if i == 0:
            if j <= a_ls[i]:
                memo_ls[i][j] = 1
            continue
        if j == 0:
            memo_ls[i][j] = 1
            continue
        if a_ls[i] < j:
            memo_ls[i][j] = (- memo_ls[i-1][max(0,j-a_ls[i]-1)] + memo_ls[i][j-1] + memo_ls[i-1][j]) % (10**7+9) #sum(memo_ls[i-1][max(0,j - a_ls[i]):j+1]) % (10**9 + 7)
        else:
            memo_ls[i][j] = (memo_ls[i][j-1] + memo_ls[i-1][j]) % (10**9+7)
print(memo_ls[-1][-1])