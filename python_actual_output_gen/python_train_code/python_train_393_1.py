k = int(input())
s = list(input())
s = sorted(s)
sint = list(map(int,s))
print(sint)
ssum = sum(sint)
print(ssum)
if(ssum >= k):
	print("0")
else:
	ssum = ssum - k
	i=0
	c=0
	while(i<len(s)):
		ssum = ssum + 9 - sint[i];
		c += 1
		if(ssum>=0):
			break
		i += 1
	# print("::")
	print(c)