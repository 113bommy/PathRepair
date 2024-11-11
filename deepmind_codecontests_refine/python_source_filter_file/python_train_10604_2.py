s=input()
ans="CODEFESTIVAL2016"
ans=0
for i in range(16):
	if s[i]!=ans[i]:
		ans+=1
print(ans)