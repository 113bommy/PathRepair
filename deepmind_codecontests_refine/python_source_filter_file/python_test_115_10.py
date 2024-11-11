for _ in range(int(input())):
	n,h=map(int,input().split())
	a=list(map(int,input().split()))

	l=1
	r=10**18

	while l<=r:
		m=(l+r)//2
		s=m
		for i in range(n-1):
			s+=min(m,a[i+1]-a[i])
			print(s)

		if s<h:
			l=m+1

		else:
			r=m-1

	print(r+1)

	








	
		



	

	




	






		
	

			




		





		
	

	
	
		
		



	















