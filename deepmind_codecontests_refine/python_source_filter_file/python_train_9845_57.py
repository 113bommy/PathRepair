n = int(input())
ip = input()
i=0
countA=countD=0
if n%2==0:
	half=int(n/2)
	while i<n:
		if ip[i]=='A':
			countA+=1
			if countA>half:
				print('Anton')
				exit()
		else:
			countD+=1
			if countD>half:
				print('Danik')
				exit()
		i+=1
	print('Friendship')
else:
	half=int(n/2)+1
	while i<n:
		if ip[i]=='A':
			countA+=1
			if countA==half:
				print('Anton')
				exit()
		else:
			countD+=1
			if countD==half:
				print('Danik')
				exit()