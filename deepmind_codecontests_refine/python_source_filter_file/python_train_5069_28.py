n = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
l = []
even = 0
odd = 0
for i in range(n[0]):
	if(a[i]%2==0):
		even += 1
	else:
		odd+=1
	if(even == odd and i!=(n[0]-1)):
		l.append(a[i+1]-a[i])
l.sort()
c = 0
s = 0
for i in l:
	s += i
	c += 1
	if(s>n[1]):
		c-=1
		break
print(c)

