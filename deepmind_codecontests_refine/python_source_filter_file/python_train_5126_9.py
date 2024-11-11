for _ in range(int(input())):
	n,x = map(int,input().split())
	ls = [int(x) for x in input().split()]
	s = set(ls)
	ls = list(s)
	cnt = 0
	a = 1
	if ls[0] != 1:
		ls.insert(0,1)
		x-=1
	while True:
		if a in ls:
			cnt+=1
		else:
			if x >0:
				cnt+=1
				x-=1
			else:
				break
 
		a+=1
	print(cnt)
 
 