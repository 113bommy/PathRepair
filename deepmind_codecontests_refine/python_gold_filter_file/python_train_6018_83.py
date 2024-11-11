S = input()
memo_ls = [[0 for j in range(13)] for i in range(len(S) + 1)]
memo_ls[0][0] = 1
for i in range(len(S)):
    for _ in range(10):
        if S[i] != "?" and int(S[i]) != _:
            continue
        for j in range(13):
            memo_ls[i + 1][(j * 10 + _) % 13] += memo_ls[i][j]
    for j in range(13):
        memo_ls[i + 1][j] %= 10**9+7

print(memo_ls[len(S)][5])