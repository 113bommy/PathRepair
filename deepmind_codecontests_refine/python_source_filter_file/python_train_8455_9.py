t=int(input())
for i in range(t):
	n=int(input())
	l=list(map(int,input().split()))
	dict={}
	for i in range(len(l)):
		dict[l[i]]=[0,0]
	for i in range(len(l)):
		dict[l[i]][0]=dict[l[i]][0]+1
		# if(l[i] not in dict.keys()):
		if(dict[l[i]][0]<2):
			dict[l[i]][1]=i
		# print(dict)
		flag=0
		if(dict[l[i]][0]>2):
			print("fir")
			print("YES")
			flag=1
			break
		if(dict[l[i]][0]==2):
			# print("why",i,dict[l[i]][1]+1)
			if(i>dict[l[i]][1]+1):
				print("sec")
				print("YES")
				flag=1
				break
	if(flag==0):
		print("NO")
