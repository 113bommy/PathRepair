n,m=map(int,input().split())
if n%2==0:
	k=n//2
else:
	k=n//2 +1
count=0
while k!=n:
	if k%m==0:
		print(k)
		count+=1
		break
	k+=1
if count==0:
	print(-1)
