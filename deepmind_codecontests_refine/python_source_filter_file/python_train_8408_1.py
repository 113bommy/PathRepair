from sys import exit

x=int(input())
for i in range(0,101):
	for j in range(-100,i):
		if i**5-j**5==x:
			print(i,j)
			exit()