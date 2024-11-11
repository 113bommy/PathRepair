N,A,B = map(int, input().split())

if abs(A-B)%2==0:
	print(int(abs(A-B)//2))
else:
	min(N-B,A-1)+1+((B=A-1)//2)