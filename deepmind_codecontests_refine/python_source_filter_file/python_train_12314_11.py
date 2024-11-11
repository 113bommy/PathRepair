for _ in range(int(input())):
	l = int(input())
	arr = list(map(int, input().split()))
	if len(set(arr)) == l:
		print("YES")
	else:
		print("NO")
	'''
	#arr2 = tuple(i - 1 for i in arr if i)
	s1 = arr[0] - 1 if arr[0] else 0
	s2 = sum(i - 1 for i in arr[1:] if i)
	for i in range(l - 1):
		s1 += arr[i] - 1
		s2 -= arr[i] - 1
		if not arr[i]:
			continue
		if s1 == s2:
			print("YES")
			break
	else:
		print("NO")
		'''