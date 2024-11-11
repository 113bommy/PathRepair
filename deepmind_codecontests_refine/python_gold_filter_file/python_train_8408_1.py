from sys import exit

x=int(input())
for i in range(0,201):
	for j in range(-200,i):
		if i**5-j**5==x:
			print(i,j)
			exit()