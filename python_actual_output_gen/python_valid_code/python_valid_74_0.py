N=int(input())
res=""
while N!=0:
	if N%2==0:
		res+="0"
	else:
		N-=1
		res+="1"
	print(N)
	N//=-2
if len(res)==0:
	res="0"
print(res[::-1])
