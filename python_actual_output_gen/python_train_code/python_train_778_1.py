a1,a2,a3,a4=map(int,input().split(" "))
s=list(str(input()))
print(s)
l=0
for i in s:
	if i=="1":
		l+=a1
	elif i=="2":
		l+=a2
	elif i=="3":
		l+=a3
	elif i=="4":
		l+=a4
print(l)