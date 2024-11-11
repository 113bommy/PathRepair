from sys import stdin,stdout
input = stdin.readline
# print = stdout.write

for __ in range(int(input())):
	n=int(input())
	if(n==1):
		print(1)
	elif(n==2):
		print(2)
	else:
		# print(n*(n-1))
		p=(4*n -2)//2
		print(p-1)


