n, m = map(int, input().split())
answs = [[0] * 5 for i in range(m)]
for i in range(n):
    ians = input()
    for j in range(m):
        answs[j][ord(ians[j]) - ord('A')] += 1
bst = [0] * m
for i in range(m):
    maxj = -1
    maxsum = -1
    for j in range(5):
        if answs[i][j] > maxsum:
            maxj = j
            maxsum = answs[i][j]
    bst[i] = maxj
W = list(map(int, input().split()))
ans = 0
for i in range(m):
    ans += W[bst[i]] * answs[i][bst[i]]
print(ans)