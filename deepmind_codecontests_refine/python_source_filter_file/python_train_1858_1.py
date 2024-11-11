H, W = [int(_) for _ in input().split()]
memo = {}
for _ in range(H):
    for _ in input():
        memo[_] = memo.get(_, 0) + 1
count = [0] * 4
for k, v in memo.items():
    count[v % 4] += 1
ans = 'No'
if H * W % 2:
    if count[1] * count[3] == 1 and 1 + 2 * count[2] <= H + W - 1:
        ans = 'Yes'
elif H % 2:
    if count[1] == count[3] == 0 and 2 * count[2] <= W and (
            W - 2 * count[2]) % 4 == 0:
        ans = 'Yes'
elif W % 2:
    if count[1] == count[3] == 0 and 2 * count[2] <= H and (
            H - 2 * count[2]) % 4 == 0:
        ans = 'Yes'
else:
    if count[1] == count[2] == count[3] == 0:
        ans = 'Yes'
print(ans)
