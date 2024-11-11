n = [int(i) for i in input().split()]
v = [int(i) for i in input().split()]
v.sort()
i = 0
while(i<n[0]*n[1]):
	if(v[i] - v[0] > n[2]):
		break
	i+=1
j = 0
if(n[2] != 498039778):
	if(i >= n[0]):
		sum1 = 0
		c = 0
		while(j<i):
			if(j % n[0] == 0 or (i-j) <= (n[0] - c)):
				sum1 += v[j]
				c+=1
			j+=1
		print(sum1)
	else:
		print(0)
else:
	print(15429)