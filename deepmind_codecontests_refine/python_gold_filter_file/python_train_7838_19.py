c,f=0,0; n=int(input()); l=sorted(map(int,input().split()))
for i in range(len(l)):
	if c>=n:f=1;break
	c+=l[len(l)-i-1]
print([-1,[i+1,i][f==1]][c>=n])