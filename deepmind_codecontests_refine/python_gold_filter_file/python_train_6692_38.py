for i in range(int(input())):
	n = int(input())
	if(n<=9):
		if(n==1):
			print(1)
		else:
			print(1+10*(n-1))
		continue
	if(n==11 or n==111 or n==1111):
		s = len(str(n))
		print((s*(s+1))//2)
		continue
	if(n==22 or n==222 or n==2222):
		s = len(str(n))
		print(10+(s*(s+1))//2)
		continue
	if(n==33 or n==333 or n==3333):
		s = len(str(n))
		print(20+(s*(s+1))//2)
		continue
	if(n==44 or n==444 or n==4444):
		s = len(str(n))
		print(30+(s*(s+1))//2)
		continue
	if(n==55 or n==555 or n==5555):
		s = len(str(n))
		print(40+(s*(s+1))//2)
		continue
	if(n==66 or n==666 or n==6666):
		s = len(str(n))
		print(50+(s*(s+1))//2)
		continue
	if(n==77 or n==777 or n==7777):
		s = len(str(n))
		print(60+(s*(s+1))//2)
		continue
	if(n==88 or n==888 or n==8888):
		s = len(str(n))
		print(70+(s*(s+1))//2)
		continue
	if(n==99 or n==999 or n==9999):
		s = len(str(n))
		print(80+(s*(s+1))//2)
		continue
		