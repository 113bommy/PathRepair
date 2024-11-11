l1=[int(x) for x in input().split()]
l2=[int(x) for x in input().split()]
l2.sort()
i=0
out=0
while i<l1[0] and l2[i]<0:
	out+=l2[i]
	i+=1
print(abs(out))	