for i in range(int(input())):
	n, k1, k2 = list(map(int,input().split()))
	k1_s = list(map(int,input().split()))
	k2_s = list(map(int,input().split()))
	
	if sum(k1_s) > sum(k2_s):
		print('YES')
	
	else:
		print('NO')	