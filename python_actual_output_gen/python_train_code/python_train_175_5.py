n,k=[int(i)for i in input().split()]
w=[int(i)for i in input().split()]
i=0
x=0
for i in w:
	if i%k==0:
		x+=i//k
	else :
		x+=i//k+1
print(x//2 if x%k==0 else x//2+1)