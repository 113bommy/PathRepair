n = int(input())
ga, sa, ba = list(map(int, input().split()))
gb, sb, bb = list(map(int, input().split()))

w_ab = []
v_ab = []

if ga < gb:
    w_ab.append(ga)
    v_ab.append(gb)
if sa < sb:
    w_ab.append(sa)
    v_ab.append(sb)
if ba < bb:
    w_ab.append(ba)
    v_ab.append(bb)

num = (n+1)*(len(w_ab)+1)
dp = [0]*num
for i in range(len(w_ab)):
    for j in range(n+1):
        if j < w_ab[i]:
            dp[(i+1)*(n+1) + j] = dp[i*(n+1) + j]
        else:
            dp[(i+1)*(n+1) + j] = max(dp[i*(n+1) + j], dp[(i+1)*(n+1) + j - w_ab[i]] + v_ab[i])
ans = 0
length = len(w_ab)
for j in range(n+1):
    ans = max(ans, dp[length*(n+1) + j] + n-j)
n = ans

w_ab = []
v_ab = []

if ga > gb:
    w_ab.append(gb)
    v_ab.append(ga)
if sa > sb:
    w_ab.append(sb)
    v_ab.append(sa)
if ba > bb:
    w_ab.append(bb)
    v_ab.append(ba)

num = (n+1)*(len(w_ab)+1)
dp = [0]*num
for i in range(len(w_ab)):
    for j in range(n+1):
        if j < w_ab[i]:
            dp[(i+1)*(n+1) + j] = dp[i*(n+1) + j]
        else:
            dp[(i+1)*(n+1) + j] = max(dp[i*(n+1) + j], dp[(i+1)*(n+1) + j - w_ab[i]] + v_ab[i])

length = len(w_ab)
for i in range(n+1):
    ans = max(ans, dp[length*(n+1) + j] + n-j)
print(ans)
  