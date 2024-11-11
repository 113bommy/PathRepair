#coding:utf-8

q = int(input())
for i in range (q): 
	liste = input().split()
	n = int(liste[0])
	a = int(liste[1])
	b = int(liste[2])
	if 2*a < b:
		print(n*a)
	else:
		if n%2==0:
			print(n/2*b)
		else :
			print(int((n/2))*b+a)