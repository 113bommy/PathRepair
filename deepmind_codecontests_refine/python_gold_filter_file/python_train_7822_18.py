from collections import deque
n = int(input())
a = deque(map(int, input().split()))

cnt = 0
ans = []
last = 0

while cnt < n and max(a[0], a[-1]) > last:
	cnt += 1
	if a[0] > last and (a[0] < a[-1] or a[-1] <= last):
		ans.append('L')
		last = a.popleft()
	else:
		ans.append('R')
		last = a.pop()

print(cnt)
print("".join(ans))