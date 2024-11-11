ia=[int(i) for i in input().split(" ")]
c=0
for i in range(ia[0],ia[1]+1):
	if ia[2]%i==0:
		c+=1
print(c)