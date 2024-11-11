s=input()
t=input()
ls=len(s)
lt=len(t)
ans=lt

for i in range(0,ls-lt):
	count = 0
	for j in range(lt):
		if s[i+j]!=t[j]:
			count+=1
	if count<ans:
		ans=count
print(ans)