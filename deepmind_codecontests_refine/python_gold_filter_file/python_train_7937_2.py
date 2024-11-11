for i in range(int(input())):
	N=int(input())
	counter=0
	lineup=[int(x) for x in input().split()]
	for i in range(N):
		if lineup[i]==i+1:
			counter+=1
	if counter==N:
		print("0")
		continue
	check1=0
	while lineup[check1]==check1+1:
		check1+=1
		counter-=1
	check1=0
	while lineup[N-1-check1]==N-check1:
		check1+=1
		counter-=1
	if counter==0:
		print("1")
	else:
		print("2")