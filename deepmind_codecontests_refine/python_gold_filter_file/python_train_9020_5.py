N = int(input());
array = list(map(int,input().split()));
mp={}
maxi=0;
cnt=0;
for i in range(0,N):
	x=array[i];
	if(mp.get(x-1)==None):
		mp[x]=1
	if(mp.get(x-1)!=None):
		mp[x]=1+mp[x-1]
	if(maxi<mp[x]):
		maxi=mp[x]
		cnt=x
print(maxi)
ans=cnt-maxi+1		
for i in range(0,N):
	if(array[i]==ans):
		print(i+1,end=" ")
		ans+=1

		
		

