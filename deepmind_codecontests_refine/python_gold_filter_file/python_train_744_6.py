for i in range(int(input())):
	n=int(input())
	arr=list(map(int,input().split()))
	if n==1 or n==2 or n==3:
		print("YES")
	else:
		s=""
		for i in arr:
			s=s+str(i)+" "
		s=s*2
		s1=""
		s2=""
		for i in range(1,n+1):
			s1=s1+str(i)+" "
			s2=" "+str(i)+s2
		
		if((s1 in s) or (s2 in s)):
			print("YES")
		else:
			print("NO")
