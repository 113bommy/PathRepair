n=int(input())
if n==1:
	print(1)
	exit()
xy = sorted([list(map(int,input().split())) for i in range(n)])
p=q=0
ans=0
dic={}
for i in range(n-1):
	for j in range(i+1,n):
		p = xy[i][0]-xy[j][0]
		q = xy[i][1]-xy[j][1]
		if (p,q) in dic:
			dic[(p,q)]+=1
		else:
			dic[(p,q)]=1
print(n-max(dic.values()))