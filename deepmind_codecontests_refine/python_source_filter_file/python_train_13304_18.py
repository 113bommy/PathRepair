x,y=list(map(int, input().split()))

if y>x+2020:
	y=x+2020

ans=2019
for i in range (x,y+1):
	for j in range (x+1,y+1):
		if (i*j)%2019<ans:
			ans=(i*j)%2019
print(ans)