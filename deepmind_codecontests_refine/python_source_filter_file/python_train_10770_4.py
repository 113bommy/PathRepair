if __name__ == "__main__":	
	n, l, x, y = list(map(int, input().split()))
	v = list(map(int, input().split()))
	s = set(v)

	cx = 0
	for i in range(n):
		if v[i]+x in s:
			cx = 1
			break
	
	cy = 0
	for i in range(n):
		if v[i]+y in s:
			cy = 1
			break
	
	count = 0
	ans = []

	if cx==0:
		count += 1
		ans.append(x)
	if cy==0:
		count += 1
		ans.append(y)

	if count==2:
		for i in range(n):
			if (v[i]+x+y in s):
				count = 1
				ans = [v[i]+x]
				break
				
	if count==2:
		for i in range(n):
			if (v[i]+x-y in s):
				if v[i]+x<=l:
					count = 1
					ans = [v[i]+x]
					break
				elif v[i]-y<=l:
					count = 1
					ans = [v[i]-y]
					break

	print(count)
	if count!=0:
		print(*ans)
