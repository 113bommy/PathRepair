n=int(input())
a=list(map(int,input().split()))
avg=int((sum(a)/n)*2)
l=[]
for i in range(n):
	for j in range(n):
		if i!=j and a[j]!=0:
			if a[i]+a[j]==avg and ((i+1) not in l) and (j+1) not in l:
				a[j]==0
				l.append(i+1)
				l.append(j+1)
				print(i+1,j+1)
				break