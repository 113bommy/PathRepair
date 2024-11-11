def solve():
	n = int(input())
	arr = [int(x) for x in input().split()]
	s = sum(arr)
	res=0
	for i in range(n):
		res+=arr[i]
		if res>=s//2:
			print(i+1)
			return
solve()