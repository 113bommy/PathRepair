s=[input().replace('a','0').replace('b','1').replace('c','2') for _ in '111'];t=0
while True:
	if len(s[t])==0:
		print('ABC'[t])
		exit()
	a=int(s[t][0])
	s[t]=s[t][1:]
	a=t