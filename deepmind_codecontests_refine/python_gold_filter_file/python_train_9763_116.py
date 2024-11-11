A,B,C,K = map(int,input().split())
if A + B >= K:
	print(min(K,A))
else:
	print(A-(K-(A+B)))