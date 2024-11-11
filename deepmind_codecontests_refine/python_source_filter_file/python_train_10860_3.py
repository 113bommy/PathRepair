def tree(a,k,q):
	ans=[0]*(pow(2,k+1))
	a=a+["l"] #0 index this bitch
	a=a[::-1] # make winning shit id at 1
	for i in range((1<<k)-1,(1<<(k+1))): #set asnwers from 2**k -1 to ....
		ans[i]=1
	for i in range((1<<k)-1,0,-1): # place default answers from bottom to win (win id=1)
		if a[i]=="0":
			ans[i]+=ans[2*i+1]
		elif a[i]=="1":
			ans[i]+=ans[2*i] # only one
		else:
			ans[i]=ans[2*i]+ans[2*i+1] #both l and r

	for p,ch in q:
		p=(1<<k)-p #change indexing of input as we changed
		# print(p)
		a[p]=ch
		while p: #recalc answers /update answers
			if a[p]=="0":
				ans[p]=ans[2*p+1]
			elif a[p]=="1":
				ans[p]=ans[2*p]
			else:
				ans[p]=ans[2*p]+ans[2*p+1]
			p//=2
		print(ans[1])



k=int(input())
a=list(input())
q=[]
for i in range(int(input())):
	x,y=map(str,input().strip().split())
	x=int(x)
	q.append((x,y))

tree(a,k,q)

