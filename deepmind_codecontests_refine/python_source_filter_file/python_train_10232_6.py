import math
for _ in range(int(input())):
	n = int(input())
	a = str(input())
	d = [1]
	prev = a[0]
	for i in range(1,n):
		if a[i]==prev:
			d[-1]+=1
		else:
			prev = a[i]
			d.append(1)

	# print(d)
	ans = 0
	i = j = 0
	n = len(d)
	c = 0
	flag = True
	while (i<n and (j<=n-1 and d[j]!=0)):
		if flag==True:
			for k in range(j,n):
				if d[k]>1:
					j = k
					break
				else:
					j = k
			# if j==n-1:
			# 	flag = False
			# 	temp = 0
			d[j]-=1
		# else:
		# 	for k in range(temp,n):
		# 		if d[temp]>0:
		# 			temp = k
		# 			break
		# 	d[temp]-=1	
		for k in range(i,n):
			if d[k]>0:
				i = k
				break
		d[i] = 0
		ans+=1
		# print(i,j)
		# if c==5:
		# 	breaks
		# c+=1
		# print(d)
	count = 0
	for i in d:
		if i>0:
			count+=1
	ans+= (count+1)//2
	print(ans)