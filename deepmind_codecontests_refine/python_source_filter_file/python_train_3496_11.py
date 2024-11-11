n, k = input().split()
k = int(k)
ans = 0
count = 0
for num in n[::-1]:
	if count == k:
		print(ans)
		exit()
	if num == 0:
		count += 1
	if num != 0:
		ans += 1
print(ans + count - 1)