a = input()
b = input()
n = len(a)
m = len(b)
ans = 0
li = []
for i in range(1, min(n, m) + 1):
    if n%i == 0 and m%i == 0:
        li.append(i)
for x in li:
    if a[:x] * (n // x) == a and b[:x] * (m // x) == b:
        ans += 1
    #print(dp[x - 1] * (n // x), dp[x - 1] * (m // x))
print(ans)
