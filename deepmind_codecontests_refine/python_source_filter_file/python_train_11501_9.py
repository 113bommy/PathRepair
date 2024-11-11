def LenAndSum(m,s):
	max=""
	min=""
	count=0
	s2=s
	if m==1 and s==0:
		print("0 0")
		return
	if (m>0 and s==0) or 10**m<=s:
		print("-1 -1")
		return
	for i in range(m):
		if(s-9)>=0:
			max=max+"9"
			s-=9
		elif s>0:
			max=max+str(s)
			s=0
		else:
			max=max+"0"
			count+=1
	for i in range(m):
		if(s2-9)>0:
			min=min+"9"
			s2-=9
		elif s2>0 and i==m-1:
			min=str(s2)+min
			s2=0
		elif s2>1 and i!=m:
			min=str(s2-1)+min
			s2=1
		elif s2==1 and i<(m-1):
			min="0"+min

	print(min," ", max)


inp = input()
m=int(inp.split()[0])
s=int(inp.split()[1])
LenAndSum(m,s)