n=int(input())
li=[int(i) for i in input().split(" ")]
ans=1
m=1
x=li[0]
for i in range(1,n):
	if li[i]<=2*x and li[i]>x:m+=1
	else:m=1
	ans=max(ans,m)
	x=li[i]
print(ans)
	