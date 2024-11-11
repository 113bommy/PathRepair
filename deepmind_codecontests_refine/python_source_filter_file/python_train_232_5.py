# for _ in range(int(input())):
n = int(input())
# n, m = map(int, input().split())
l = list(map(int, input().split()))
# l = [list(map(int, input().split())) for i in range(n)]

if n == 1:
	print(1, 1)
	print(0)
	print(1, 1)
	print(0)
	print(1, 1)
	print(-l[0])

else:
	print(1,1)
	print(-l[0])
	l[0] = 0
	print(2, n)

	valarr = []
	for i in range(1, n):
		temp = n-1
		val = (l[i]%temp)*temp
		l[i]+=val
		valarr.append(val)
	print(*valarr)

	print(1, n)
	arr = []
	for i in range(n):
		arr.append(-l[i])
	print(*arr)