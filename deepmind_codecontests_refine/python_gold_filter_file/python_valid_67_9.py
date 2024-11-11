import math
def iseven(n):
	return n%2==0
def isprime(num):
	for i in range(2, num//2):
		if (num % i) == 0:
			return False
	return True	

t = int(input())
for _ in range(t):
	a, b, c = [int(x) for x in input().split()]
	n=abs(b-a)-1
	n=2*n
	n+=2
	
	if iseven(n) and c<=n and b<=n and a<=n:
		if 2*c>n:
			print(c-abs(b-a))
		else:
			print(c+abs(b-a))
	else:
		print(-1)





		

	





	# x1, y1 = [int(x) for x in input().split()]

	# c = list(map(int, input().split()))
	# print(*ans,sep='\n')


