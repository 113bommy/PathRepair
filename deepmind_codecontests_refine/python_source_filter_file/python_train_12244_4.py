n,k=map(int,input().split())
a=list(input())
d={}
for i in range(n):
	if a[i] not in d:
		d[a[i]]=1
	else:
		d[a[i]]+=1
b=min(list(d.values()))
if k>b:
	print("NO")
else:
	print("YES")