for _ in range(int(input())):
	x = int(input())
	mylist  = list(map(int,input().split()))
	amr = set(mylist)
	size = len(amr)
	out = []
	if size == 1:
		out = [1]*x
	else:
		out = [i%2+1 for i in range(x)]
		if mylist[-1] != mylist[0] and x%2 != 0 :	
			for i in range(1,x):
				if mylist[i] == mylist[i-1]:
					out.insert(i,mylist[i-1])
					out.pop(-1)
					break
		
			else:
			    out[-1] = 3
	print(len(set(out)))
	print(*out)