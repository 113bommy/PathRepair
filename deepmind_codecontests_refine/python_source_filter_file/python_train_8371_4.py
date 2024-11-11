k=1
p=r=0
for x in input():
	if x!=p:r+=1-k%2;k=0;p=x
	k+=1
print(r)