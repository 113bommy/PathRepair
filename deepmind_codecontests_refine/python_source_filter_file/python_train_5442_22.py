t =int(input())
for _ in range(t):
	n=int(input())
	a =input()
	if n%2!=0:
		for i in range(0,n,2):
			flag=0
			if int(a[i])%2!=0:
				print("1")
				flag=1
				break
			else:
				pass
			if flag==0:
				print("2")
	else:
		for i in range(1,n,2):
			flag=0
			if int(a[i])%2==0:
				print("2")
				flag=1
				break
			else:
				pass
			if flag==0:
				print("1")