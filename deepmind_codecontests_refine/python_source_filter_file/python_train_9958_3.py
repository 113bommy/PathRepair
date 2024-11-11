n,m = map(int,input().split())
l1 = list(map(int,input().split()))
l2 = list(map(int,input().split()))
i,j = 1,1
sum1 = l1[0]
sum2 = l2[0]
count = 0
while i < len(l1) and j < len(l2):
	print(sum1,sum2)
	if sum1 > sum2:
		sum2 = sum2 + l2[j]
		j = j + 1
	elif sum2 > sum1:
		sum1 = sum1 + l1[i]
		i = i + 1
	if sum2 == sum1:
		count = count + 1
		if j < len(l2):
			sum2 = l2[j]
			j = j + 1
		if i < len(l1):
			sum1 = l1[i]
			i = i + 1
count = count + 1
print(count)