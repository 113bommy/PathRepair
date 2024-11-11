x=list(input())
ans=0
check=0
for i in x:
	if i=='T':
		if check==0:
			ans+=1
		check-=1
		check=max(check,0)

	else:
		check+=1
print(ans)
		