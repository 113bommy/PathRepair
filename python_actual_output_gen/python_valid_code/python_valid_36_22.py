s=input()
ans=1
for i in range(1,4):
	if s.count("R"*i):
		ans=max(ans,i)
print(ans)
