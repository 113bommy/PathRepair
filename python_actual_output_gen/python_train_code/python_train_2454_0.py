t=int(input())
for _ in range(t):
	n,k=map(int,input().split())
	s=input()
	cnt=[[0 for i in range(26)] for j in range((k+1)//2)]

	for i in range(n):	
		cnt[min(i%k,k-i%k-1)][ord(s[i])-ord('a')]+=1
	print(cnt)

	ans=0
	for i in range(k//2):	
		ans+=2*n//k-max(cnt[i])
	if (k%2==1):
		ans+=n//k-max(cnt[k//2])

	print(ans)