n,k,p=list(map(int, input().split(' ')))
a=list(map(int, input().split(' ')))
odd, even = [],[]
for temp in a:
	if(temp%2==0):
		even.append(temp)
	else:
		odd.append(temp)
if(False and len(odd)%2!=(k-p)%2):
	print ("NO")
else:
	ans=[]
	for i in range(k): ans.append([])
	i=0
	for o in odd:
		if(i<k-p):
			ans[i].append(o)
			i+=1
		elif(i<k):
			ans[i].append(o)
			if(len(ans[i])>=2):
				i+=1
		else:
			ans[0].append(o)
	for o in even:
		if(i<k):
			ans[i].append(o)
			i+=1
		else:
			ans[0].append(o)
	print(ans)
	t=0
	for f in ans:
		cur = sum(f)
		if(len(f)==0):
			t=1000000000
		if(cur%2==1):
			t+=1
	ans.reverse()
	if(t!=k-p):
		print ("NO")
	else:
		print ("YES")
		for f in ans:
			print  (len(f), " ".join(map(str,f)))