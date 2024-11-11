def teams_possible(arr , k) :
	ans = 0
	for i in arr :
		if i+k <= 5 :
			ans += 1

	return ans//2

n, k = list(map(int, input().split()))

arr = list(map(int, input().split()))

print(teams_possible(arr, k))

