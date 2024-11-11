ls1,ls2=map(int,input().split())
s1=list(input().split())
s2=list(input().split())
c=0
l=[]
for i in s1:
	# print(i)
	for j in s2:
		# print(j)
		if i==j:	 
			l.append(j)
for i in l:
	print(i,end=" ")