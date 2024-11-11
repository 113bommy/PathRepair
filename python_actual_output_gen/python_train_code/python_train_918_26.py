t=int(input())

for _ in range(t):
	s=[int(i) for i in input().strip().split()]

	if(s[0] == 1 or s[1] == 1):
		print('YES')
	else:
		if(s[0]*s[1] % 4 ==0 ):
			print('YES')
		else:
			print("NO")