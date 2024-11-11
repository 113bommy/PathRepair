n=int(input())
a=[list(map(int,input().split())) for _ in range(n)]
b=[(i,sum(j)) for i,j in enumerate(a)]
b.sort(key=lambda x:x[1],reverse=True)
ans=0
for i in range(n):
	ans+=a[i][i%2]*(-1)**(i%2)
print(ans)