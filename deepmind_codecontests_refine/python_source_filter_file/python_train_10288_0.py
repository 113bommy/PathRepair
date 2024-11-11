n=int(input())

x=[list(map(int,input().split())) for _ in range(n)]

for i in range(101):
	for j in range(101):
		for k in range(n):
			if x[k][2]>0:
				h=x[k][2]+abs(i-x[k][0])+abs(j-x[k][1])
			break
		chk=0
		for k in range(n): 
			if x[k][2]!=max(h-abs(i-x[k][0])-abs(j-x[k][1]),0):
				chk=1
				break
		if chk==0:
			res=[i,j,h]
			break
	if chk==0:
		break

print(*res)
