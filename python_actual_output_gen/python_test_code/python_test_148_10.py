n,m=map(int,input().split())
a=sorted(map(int,input().split()))
b=sorted([list(map(int,input().split())) for i in range(m)],key=lambda x:x[1])[::-1]
i=0
for num,v in b:
	for j in range(num):
		if a[i]<v and i<n:
			a[i]=v
			i+=1
		else:
			print(sum(a))
			exit()
else:
	print(sum(a))