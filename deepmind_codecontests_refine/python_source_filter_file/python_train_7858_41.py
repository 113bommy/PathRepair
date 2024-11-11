n = int(input())
l = list(map(int,input().split()))
ll = []
llll = []
if len(l) == 1:
	print(1)

else:
	for i in range(n-1):
		if l[i] <= l[i+1]:
			ll.append(1)
		else:
			ll.append(0)
	import itertools
	lll = [len(list(v)) for k,v in itertools.groupby(ll)]
	if len(lll) == 1:
		if ll[0] == 1:
			print(n)
		else:
			print(0)
	else:
		if len(lll)%2 == 0:
			if ll[0] == 1:
				for i in range(int(len(lll)/2)):
					llll.append(lll[2*i])
			else:
				for i in range(int(len(lll)/2)):
					llll.append(lll[2*i+1])
		else:
			if ll[0] == 1:
				for i in range(int(len(lll)//2+1)):
					llll.append(lll[2*i])
			else:
				for i in range(int(len(lll)//2)):
					llll.append(lll[2*i+1])
		print(max(llll)+1)
