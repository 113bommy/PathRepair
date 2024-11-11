t = int(input())
hay8=0
for i in range(t):
	n = int(input())
	numeros = input()	
	if(n<11 or (n==11 and numeros[0]!="8")):
		print("NO")
	elif(n==11 and numeros[0]=="8"):
		print("YES")
	else:
		for j in range(n):
			if(numeros[j]=="8"):
				hay8=1
				if(n-j>=11):
					print("YES")
				else:
					print("NO")
				break
		if(hay8==0):
			print("NO")