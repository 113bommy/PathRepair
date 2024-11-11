n,k = map(int,input().split())
l = list(map(int,input().split()))
i=0
j=n-1
c=0
while i<=j:
	if k >= l[i]:
		i+=1
		c+=1
	elif k>=l[j]:
		j=-1
		c+=1
	else:
	    break
print(c)
