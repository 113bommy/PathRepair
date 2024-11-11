for i in range(int(input())):
	n=int(input())
	odd=0
	for j in range(n):
		s=input()
		one=s.count('1')
		zero=s.count('0')
		if(len(s)%2==0):
			if(one%2==1 or zero%2==1):
				odd+=1
		else:
			oddd=1
	if(odd%2==0):
		print(n)
	else:
		if(oddd==1):
			print(n)
		else:
			print(n-1)