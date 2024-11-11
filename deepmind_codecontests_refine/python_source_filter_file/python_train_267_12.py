c, v0, v1, a, l = list(map(int, input().split()))

count = 1
i = 0
c = c-v0
while c>0:
	c += l
	if v0+a*i < v1:
		c -= (v0+a*i)
		i +=1 
		count +=1
	else:
		c -= v1
		count +=1
print(count)