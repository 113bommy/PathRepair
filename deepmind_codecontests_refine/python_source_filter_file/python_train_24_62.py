for _ in range(int(input())):
	r=int(input())-1
	k=input().split()
	if int(k[0])+int(k[1])>int(k[r]):
		print(-1)
	else:
		print("0","1",str(r))
	