for _ in range(int(input())):
	n=int(input())
	s=input()
	ans=s
	ans2=1
	for i in range(n-1):
		if (n-i+2)%2==0:
			temp=s[i:]+s[:i]
		else:
			temp=s[i:]+s[:i:-1]
		if temp<ans:
			ans=temp
			ans2=i+1
	temp=s[::-1]
	if temp<ans:
		ans=temp
		ans2=n
	print(ans)
	print(ans2)