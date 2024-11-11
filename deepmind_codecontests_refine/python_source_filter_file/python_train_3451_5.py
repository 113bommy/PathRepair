s = {2**i -1 for i in range(25)}
n = int(input())
tbp = []
c=0
while n not in s:
	last = -1
	for i in range(20):
		if (n & (2**i)) == 0 and (2**i) < n:
			last = i
	if last == -1: 
		break # done
	n ^= (-1+2**(last+1))
	c+=1
	tbp.append(str(n))
	if n in s: break
	c+=1
	n+=1
print(c)
print(" ".join(tbp))