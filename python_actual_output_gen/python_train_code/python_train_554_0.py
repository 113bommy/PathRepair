def solve(n):
	for i in range(1,100):
		cnt=0
		for j in range(1,i+1):
			if i%j==0:
				cnt+=1
		if cnt==n:
			return(i)
while True:
	try:
		n=int(input())
		print(solve(n))
	except EOFError:
		break