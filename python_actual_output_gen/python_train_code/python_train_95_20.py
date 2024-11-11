c,v0,v1,a,l=map(int,input().split())
i,page=0,v0
day=1
# print(page)
while page<c:
	i+=1
	if page>v1:
		page+=v1-l
	else:
		page+=v0+i*a-l
	day+=1
print(day)