a=int(input())
b=int(input())
c=[1,0,2]
if b==1: print(c[a%3])
elif b==2:
	if a%3!=0 and (a%6!=1 and a%6!=2):
		print(1)
	elif a%3!=1 and (a%6==2 or a%6==3):
		print(0)
	else:
		print(2)
else:
	if a%3!=0 and (a%6==1 or a%6==2):
		print(0)
	elif a%3!=2 and (a%6!=0 and a%6!=1):
		print(2)
	else:
		print(1())