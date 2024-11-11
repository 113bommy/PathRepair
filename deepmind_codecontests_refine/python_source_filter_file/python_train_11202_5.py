p=input("")
P=p.upper()
s=input("")
S=s.upper()
r=input("")
arr=[]
for i in range(0,26):
	arr.append([p[i],s[i]])
for i in range(0,26):
	arr.append([P[i],S[i]])	
#print(arr)	
for i in range(0,len(r)):
	for j in range(0,52):
		if r[i]==arr[j][0]:
			print(arr[j][1],end="")
			break;
		elif 49<=ord(r[i])<=57:
			print(r[i],end="")
			break;
		

