for  _ in range(int(input())):
	n=int(input())
	a=[]
	flag=0
	for _ in range(n):
		arr=input()
		for i in arr:
			a.append(i)
	d={}
	for i in a:
		if i in d:
			d[i]+=1
		else:
			d[i]=1
	for i in d:
		if d[i]%2!=0:
			flag=1
			break;
	if flag==0:
		print("YES")
	else:
		print("NO")
