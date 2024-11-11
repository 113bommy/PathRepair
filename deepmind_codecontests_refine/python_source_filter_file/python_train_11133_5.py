da = list(map(int,input().split()))

k = [[0 for i in range(2)]for j in range(10001)]
i = 0
su = 0
j = 0

while da[0] + da[1] != 0:
	i = 0
	su = 0
	j = 0
	for i in range(da[0]):
		k[i][0],k[i][1] = map(int,input().split())


	sorted(k,key = lambda x: x[1],reverse = True)
	while j != i + 1:
		if da[1] > k[j][0]:
			da[1] -= k[j][0]
			j += 1
		elif da[1] <= k[j][0] and da[1] > 0:
			su += (k[j][0] - da[1]) * k[j][1]
			da[1] = 0
			j += 1
		else:
			su += k[j][0] * k[j][1]
			j += 1

	print(su)

	da = list(map(int,input().split()))

	k = [[0 for i in range(2)]for j in range(10001)]

