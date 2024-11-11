n = int(input())
w = [False for i in range(101)]
a, b = map(int, input().split())
s = -1
e = -1
cnt = 0

for i in range(n - 1):
	c, d = map(int, input().split())
	for j in range(c, d):
		w[j] = True

for i in range(a, b + 1):
	if not w[i]:
		cnt += 1

print(cnt)