k = int(input())

if k > 18*2:
	print(-1)
else:
	ans = []
	while k > 1:
		ans.append('8')
		k -= 2
	if k == 1:
		ans.append('6')

	print(int(''.join(ans)))
