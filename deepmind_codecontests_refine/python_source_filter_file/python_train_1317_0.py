n = int(input())
s = input()
i = 0
moves = 0
while(i<n):
	# print(i)
	c = 1
	if((n-i)>=i and i>0):
		for j in range(i):
			if(s[j] != s[i+j]):
				c = 0
	else:
		c = 0
	if(c == 0):
		moves += 1
		i+=1
	else:
		moves += 1
		i+=i
print(moves)
