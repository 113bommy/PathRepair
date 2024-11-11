N = int(input())
ans = N
for i in range(1, N + 1):
	count = 0
	t = i
	while t > 0:
		count += int(t % 9)
		t = int(t / 9)
	t = N - i
	while t > 0:
		count += int(t % 6)
		t = int(t / 6)
	if count < ans:
		ans = count
print(ans)