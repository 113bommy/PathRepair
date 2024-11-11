n, m = map(int, input().split())
x = (n + 1) // 2
cnt_l = -(-m // 2)
cnt_r = m // 2
ans = []
for i in range(cnt_l):
    ans.append((i+1, x-i))
for i in range(cnt_r):
    ans.append((x+1+i, 2*x-i-1))

for i in range(m):
    print(*ans[i])