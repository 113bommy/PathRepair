n, m, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

p, q = [0], [0]
for i in range(n):
	p.append(p[i] + a[i])
for i in range(m):
	q.append(q[i] + b[i])

j, ans = m, 0
for i in range(N+1):
	if a[i] > k:
		break

	while b[j] > k - a[i]:
		j -= 1

	ans = max(ans, i+j)

print(ans)