b = int(input())
g = int(input())
n = int(input())

ans = set()

for i in range(b):
	if 0 <= n - i <= g:
		ans.add((i, n - i))


for i in range(g):
	if 0 <= n - i <= b:
		ans.add((n - i, i))

print(len(ans))