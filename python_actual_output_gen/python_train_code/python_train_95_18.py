c,v0,v1,a,l = map(int,input().split())
ans = 0
i = 0
d = 0
while(d<=c):
	d = d+min(v1,v0+i*a-l)
	ans+=1
	i+=1
	if d==c:
		break
	# print(d)
print(ans)