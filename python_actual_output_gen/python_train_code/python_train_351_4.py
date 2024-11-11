n = int(input())
lst = list(map(int, input().split()))
ans = 0
cnt = 0

if n == 1:
	if lst[0] >= 15:
		ans = 15
	else:
		ans = lst[0] + 15
else:
	for i in range(0, len(lst)-1):
		if lst[0] > 15:
			ans = 15
			break
		else:
			dura = lst[i+1] - lst[i]
			#print(dura)
			if dura > 15:
				ans = lst[i] + 15
				break
			else:
				cnt += 1
	if cnt == n - 1:
		ans = lst[n-1] + 15


if ans > 90:
	ans = 90
	print(ans)
else:
	print(ans)