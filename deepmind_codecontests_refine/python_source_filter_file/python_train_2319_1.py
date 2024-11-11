T = int(input())
while T > 0:
	n = int(input())
	arr = list(map(int, input().split()))
	dis = [0]*n
	dic = {}
	res = [-1]*n
	for i in range(n):
		tmp = arr[i]-1
		if tmp not in dic.keys():
			dis[tmp] = max(dis[tmp], i+1)
		else:
			dis[tmp] = max(dis[tmp], i-dic[tmp])
		dic[tmp] = i
	for key in dic.keys():
		dis[key] = max(dis[key], n-dic[key])
	prev = n
	for i in range(n):
		if dis[i] == 0:
			continue
		else:
			start = dis[i]-1
			temp = start
			while start < prev:
				res[start] = i
				start += 1
			prev = min(prev, temp)
	print(res)

	T -= 1
