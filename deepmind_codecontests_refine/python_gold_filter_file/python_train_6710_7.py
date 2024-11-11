n=int(input())
a=input()
c,d=0,0
for i in range(n):
	if a[i]=="1":
		c+=1
		d=1
	elif a[i]=="0" and d==1:
		c+=1
		d=0
		break
	elif i==0 and a[i]=="0" and d==0:
		c+=1
		break
print(c)
