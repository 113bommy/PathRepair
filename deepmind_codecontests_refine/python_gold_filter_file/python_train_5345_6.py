a=input()
b=input()
l2=[]
l22=[]
res=0
for i in range(0, min(len(b) ,  len(a))):
	if a[i]!=b[i]:
		res+=1
		l2.append(a[i])
		l22.append(b[i])
l2.sort()
l22.sort()
if res==2 and l2==l22 and len(a )     ==  len(b):
	print("YES")
else:
	print("NO")