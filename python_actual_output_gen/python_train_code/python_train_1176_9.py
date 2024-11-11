K=int(input())
base=7%K
for i in range(K+1):
	if base%K==0:
		print(i)
		exit()
	else:
		base=(base*10+7)%K
print(-1)
