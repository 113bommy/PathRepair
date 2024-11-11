l,r=[int(x) for x in input().split()]
k=0
t=l
print('YES')
while k<(r-l+1)//2:
	print(t,t+1)
	t+=1
	k+=1