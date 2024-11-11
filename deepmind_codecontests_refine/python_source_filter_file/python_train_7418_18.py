
t=int(input())
for i in range(t):
	n=int(input())
	if(n<31):
		print("NO")
	else:
		print("YES")
		ans = n-30
		if(n==36):
			print("6 " + "10 " + "15 " + "5")
		elif(n==40):
			print("6 " + "10 " + "15 " + "9")
		elif(n==44):
			print("6 " + "10 " + "15 " + "!3")
		else:
			print("6 " + "10 " + "14 " + str(ans))

