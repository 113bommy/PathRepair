n = int(input())
a = list(map(int,input().split()))
p1,p2,x,y = 0,n-1,0,0
while p1 <= p2:
	if x<=y:
		x+=a[p1]
		p1+=1
	else:
		y+=a[p2]
		p2-=1
print(p1,n-p1)
