t=int(input())
for x in range(t):
	i=int(input())
	count=0
	ans=0
	for y in range(1,i+1,2):
		ans=ans+y
		count=count+1
		if ans==i:

			print(count)
			break
		else:
			if i<=ans:
				print(count)
				break
			