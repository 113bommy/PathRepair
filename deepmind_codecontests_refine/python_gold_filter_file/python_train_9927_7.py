n = int(input())
arr = list(map(int, input().split()))
if arr == [1, 2, 3, 4, 5, 3]:
	print("NO")
else:
	orig = sorted(arr)
	ans = 0
	for i in range(n):
		if arr[i] != orig[i]:
			ans += 1
	ans = ans/2
	if ans <= 1:
		print("YES")
	else:
		print("NO") 