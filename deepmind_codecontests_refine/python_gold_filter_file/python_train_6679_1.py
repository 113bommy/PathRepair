n=int(input())
a=list(input())
nt=0
count=0
pt=1
if(n==1):
	count=0
while(1):
	if(pt<=n-1 and nt<=n-1):
		if(a[nt]==a[pt]):
			#del pt
			a[pt]="0"
			count+=1
			pt+=1
		else:
			nt=pt+1
			pt+=2
	else:
		break
ans=[]
for i in range(n):
	if(a[i]!="0"):
		ans.append(a[i])
if(len(ans)%2==0):
	print(count)
	print(''.join(ans))
else:
	count+=1
	print(count)
	print(''.join(ans[:len(ans)-1]))