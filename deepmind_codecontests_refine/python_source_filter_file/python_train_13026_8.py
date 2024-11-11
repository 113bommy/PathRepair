n,k=map(int,input().split())
fr=dict()
a=list(map(int, input().split()))
res=list(i for i in range(n))
for i in range(n) :
	if a[i] in fr :
		fr[a[i]]+=1
	else :
		fr[a[i]]=1
mx=max(fr[a[i]] for i in range(n))
if k<mx or k>n:
	print("NO")
else :
	print("YES")
	for i in range(0,k) :
		res[i]=i+1
	for i in range(k,n) :
		if a[fr[a[i]]-1] == a[i] :
			fr[a[i]]-=1
		res[i]=fr[a[i]]
		fr[a[i]]-=1
	for i in range(0,n) :
		print(res[i],end=" ")