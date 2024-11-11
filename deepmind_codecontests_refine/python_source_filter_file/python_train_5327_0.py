T = int(input())
for i in range(T):
	n,s,t = map(int, input().split())
	if s==1 and t==1 and n >= 2:
		print(2)
	elif n == 1:
		print(1)
	elif(s==t):
		print(1)
	elif(s<t):
		print(n-s+1)
	else:
		print(n-t+1)
			
