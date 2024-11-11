a=input()
if int(a)%8==0:
	print('YES')
	print(a)
	exit()
for i in range(len(a)):
	if int(a[i])%8==0:
		print('YES')
		print(a[i])
		exit()
for i in range(len(a)):
	for j in range(len(a)):
		if int(a[i]+a[j])%8==0:
			print('YES')
			print(a[i]+a[j])
			exit()
for i in range(len(a)):
	for j in range(i,len(a)):
		for k in range(j,len(a)):
			if int(a[i]+a[j]+a[k])%8==0 and i!=j!=k:
				print('YES')
				print(a[i]+a[j]+a[k])
				exit()
print('NO')
