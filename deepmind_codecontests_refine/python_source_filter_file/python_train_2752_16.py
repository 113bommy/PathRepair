n=int(input())
l=list(map(int,input().split()))
c=0
flag=0
for i in range(n):
	c+=l[i]
	if c<0:
		flag+=1
print(flag)