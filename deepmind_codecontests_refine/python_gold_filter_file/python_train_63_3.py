n, k = map(int, input().split())
arr = list(map(int, input().split()))
arr2 = list()
for v in arr:
	if k%v == 0:
		arr2 += [v]
print(k//max(arr2))