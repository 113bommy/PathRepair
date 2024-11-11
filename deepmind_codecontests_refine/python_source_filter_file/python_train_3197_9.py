def a():
	n = int(input())
	s = input()
	if (n == 1):
		if s[0]=='0':print("No")
		else: print("Yes")
		return
	for i in range(1,n):
		if(s[i]=="1" and s[i-1]=="1"):
			print("No")
			return
	
	if(n>=2):
		if(s[0]=='0' and s[1]=='0'):
			print("No")
			return
		if(s[n-1]=='0' and s[n-1]=='0'):
			print("No")
			return
	for i in range(1,n-1):
		if(s[i-1]=='0' and s[i]=='0' and s[i+1]=='0'):
			print("No")
			return
		
	print("Yes")



a()