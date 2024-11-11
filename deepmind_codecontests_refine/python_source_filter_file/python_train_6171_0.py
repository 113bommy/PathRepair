a=list(map(int,input().split()));n=int(input());s=list(map(int,input().split()));b=[];i=j=0;ans=10**18;cs=[0]*n;nz=1;z=n*6
for i in range(n):
	for j in a:b.append((s[i]-j)*n+i)
b.sort();cs[b[0]%n]+=1
while j<z:
	while j+1<z and nz<n:
		j+=1;cs[b[j]%n]+=1
		if cs[b[j]%n]==1:nz+=1
	while nz==n:
		ans=min(ans,b[j]//n-b[i]//n);cs[b[i]%n]-=1
		if cs[b[i]%n]==0:nz-=1
		i+=1
	if j+1==z:break
print(ans)