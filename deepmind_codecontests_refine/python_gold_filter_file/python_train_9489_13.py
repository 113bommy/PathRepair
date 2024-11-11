def thanos(arr,n):
	if sorted(arr)==arr:
		return n
	elif n==1:
		return 1
	else:
		num=int(n/2)
		return max(thanos(arr[:num],num) ,thanos(arr[num:],num))


def solve():
	n=int(input())
	arr=[int(x) for x in input().split()]
	print(thanos(arr,n))


solve()
