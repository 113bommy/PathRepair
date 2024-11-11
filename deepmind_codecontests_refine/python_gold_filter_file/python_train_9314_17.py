n,x,y=map(int,input().split())
vis=[0]*n
co_ords=[]
for i in range(n):
	co_ords.append(list(map(int,input().split())))

ans=0
for i in range(n):
	if vis[i]==0:
		vis[i]=1
		ans+=1
		c1x=co_ords[i][0]
		c1y=co_ords[i][1]
		for j in range(i+1,n):
			if vis[j]:
				continue
			c2x=co_ords[j][0]
			c2y=co_ords[j][1]
			if (c2y-y)==0 and (c1y-y)==0:
				vis[j]+=1
			elif c2y==y or c1y==y:
				continue
			elif ((c2x-x)/(c2y-y))==((c1x-x)/(c1y-y)):
				vis[j]+=1

print(ans)
