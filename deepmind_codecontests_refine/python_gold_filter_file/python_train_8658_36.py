n, l, r = map(int, input().split())
min_ans = 0
max_ans = 0
for counter in range(1, n+1):
    if counter < l:
        min_ans += 2**counter
    else:
        min_ans += 1

    if counter < r:
        max_ans += 2 ** (counter - 1)
    else:
        max_ans += 2 ** (r - 1)
print(min_ans, max_ans)