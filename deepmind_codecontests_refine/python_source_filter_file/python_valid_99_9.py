import math
from collections import OrderedDict		


t = int(input())
while(t>0):
	n = int(input())
	s = input()
	greedy = []
	for i in range(0,n):
		if(s[i]=='2'):
			greedy.append(i)
	# print(greedy)

	m = len(greedy)		
	# print("m=",m)
	if(len(greedy)==1 or len(greedy)==2):
		print("NO")
	elif(m==0):
		print("YES")
		i=0
		while(i<n):
			for k in range(0,n):
				if(k==i):
					print("X",end="")
				else:	
					print("=",end="")
			print()
			i+=1	
	else:
		print("YES")
		i = 0
		j = 0
		while(i<n):
			if(j==m-1 and i==greedy[m-1]):
				# print("1")
				for k in range(0,n):
					if(k==greedy[0]):
						print("-",end="")
					elif(k==greedy[m-2]):
						print("+",end="")	
					elif(k==greedy[j]):
						print("X",end="")
					else:
						print("=",end="")
				print()
			elif(j==0 and i==greedy[0]):
				# print("2")

				for k in range(0,n):
					if(k==greedy[1]):
						print("-",end="")
					elif(k==greedy[m-1]):
						print("+",end="")	
					elif(k==j):
						print("X",end="")
					else:
						print("=",end="")
				j+=1	
				print()	
			elif(j<m and i==greedy[j]):
				# print("3")

				for k in range(0,n):
					if(k==greedy[j+1]):
						print("-",end="")
					elif(k==greedy[j-1]):
						print("+",end="")	
					elif(k==greedy[j]):
						print("X",end="")
					else:
						print("=",end="")
				print()	
				j+=1
			else:
				# print("4")

				for k in range(0,n):
					if(k==i):
						print("X",end="")

					else:
						print("=",end="")
				print()		
			i+=1
								


	t-=1 							
			

#							▀█ ▄█ █▀█ █▀█ 
#							█▄ ░█ █▄█ █▄█



















