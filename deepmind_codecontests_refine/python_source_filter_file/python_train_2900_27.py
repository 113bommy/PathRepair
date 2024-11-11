X = list(map(int, input().split()))

ans1 = 0
# IJL
if X[0] > 0 and X[3] > 0 and X[4] > 0:
    i, j, l = X[0] - 1, X[3] - 1, X[4] - 1
    ans1 += 6
    ans1 += 4 * (i // 2) + 6 * (j // 2) + 6 * (l // 2)
    ans1 += 2 * X[1]

i, j, l = X[0], X[3], X[4]
ans2 = 4 * (i // 2) + 6 * (j // 2) + 6 * (l // 2) + 2 * X[1]

print(max(ans1, ans2) // 2)
