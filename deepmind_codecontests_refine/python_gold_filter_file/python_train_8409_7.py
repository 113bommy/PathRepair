x=int(input())
ans=x-1
cnt=0
while cnt==0:
	cnt=1
	ans+=1
	for i in range(2,ans):
		if ans%i==0:
			cnt=0
print(ans)