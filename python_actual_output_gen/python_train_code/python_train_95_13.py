c,v0,v1,a,l = map(int,input().split())
pos = v0
day = 1
add = v0
while(pos<c):
	add = min(v1,v0+a)
	pos+=add-l
	day+=1
print(day)