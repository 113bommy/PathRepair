n,m =map(int,input().split())
height = list(map(int,input().split()))
ans=sum(height[:m])
a=[ans]
if(ans==m):
	print(0)
else:
	for i in range(1,n-m):
		a.append(a[-1]+height[m+i-1]-height[i-1])
			
	print(a.index(min(a))+1)