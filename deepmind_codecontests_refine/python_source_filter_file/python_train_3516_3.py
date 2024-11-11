n=int(input())
a=list(map(int,input().split()))
p=0
for x in a:
	p^=x
ans=[]
for x in a:
	ans.append(p^x)
print(ans)