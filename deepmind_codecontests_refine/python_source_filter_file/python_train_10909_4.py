n=int(input())
s=input()
ans=0
for i in range(1,1000):
	i=str(i)
	i=(3-len(i))*"0"+i
	r=0
	for j in range(n):
		if s[j]==i[r]:
			r+=1
		if r==3:
			break
	if r==3:
		ans+=1
print(ans)