year=int(input())
k=True
for i in range(year+1,9000):
	years=[int(x)for x in list(str(i))]
	for digit in years:
		if years.count(digit)!=1:
			k=False
	if k==True:
		print(i)
		exit()
	k=True
