N, K = map(int, input().split())
a = list(map(int, input().split()))

sa = [0]
sb = [0]
for i in range(N):
    sa.append(sa[-1] + a[i])
    sb.append(sb[-1] + max(0, a[i]))

ans = 0
for i in range(N - K + 1):
	a = sa[i + K] - sa[i]
	b = sb[i + K] - sb[i]
    ans = max(ans, sb[N] - b + max(a, 0))

print(ans)
