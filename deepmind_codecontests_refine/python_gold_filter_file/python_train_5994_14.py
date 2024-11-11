s=input()
n=len(s)
a=[]
a.append(s)
k=1

for i in range(n):
	s=s[-1]+s[:n-1]

	if s not in a:
		a.append(s)
		k+=1
print(k)