X=int(input())
ans=0
for b in range(1,33):
	for p in range(2,11):
		if b**p<=X:
			ans=max(b**p,ans)
print(ans)