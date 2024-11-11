nk = list(map(int, input().split()))
a = list(map(int, input().split()))
count = 0
temp = 0
for i in range(nk[0]):
	temp = 0
	if len(str(a[i])) < nk[1]:
		count += 1
	else:
		for j in range(len(str(a[i]))):
			if str(a[i])[j] == '4' or str(a[i])[j] == '7':
				temp +=1
			if temp > nk[1]:
				break
	if temp <= nk[1]:
		count += 1
print(count)