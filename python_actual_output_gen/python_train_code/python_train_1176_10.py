K=int(input())
base=7%K
for i in range(1,K):
	if base%K==0:
		print(i)
		exit()
	else:
		base=(base*10+7)%K
print(-1)
