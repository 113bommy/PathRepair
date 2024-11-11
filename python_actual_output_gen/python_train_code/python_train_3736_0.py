MOD = int(1e9 + 7)
n, h = map(int, input().split(" "))
val = list(map(int, input().split(" ")))
pre = 1
ans = 1
for i in range(1, n):
    if val[i] > h:
        ans = 0
        break
    if val[i-1] - val[i] == 1:
        ans = pre
    if val[i-1] - val[i] == -1:
        ans = pre * (h - val[i-1])
    if val[i-1] == val[i]:
        ans = pre + pre * (h - val[i])
    if abs(val[i] - val[i-1]) > 1:
        ans = 0
        break
    pre = ans
print(ans % MOD)
