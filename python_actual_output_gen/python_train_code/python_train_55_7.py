_, A =input(), list(map(int,input().split()))
if(sum(A)%200 == 0 and (len(A)%2 or (len(A)%2 == 1 and 100 in A and 200 in A))):
	print("YES")
else:
	print('NO')