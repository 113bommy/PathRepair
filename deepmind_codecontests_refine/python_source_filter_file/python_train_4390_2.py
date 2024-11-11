t = int(input())
for z in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	a.sort()
	pred = a[0]*a[-1]
	flag = 1;
	j=0
	cnt=0
	check = int(pred**(0.5) +1)
	for i in range(2,check+1):
		if(pred%i==0):
			cnt+=1
			if(pred//i != i):
				cnt+=1
			if(a[j]==i):
				j+=1
			else:
				flag = 0
				break
	for i in range(n):
		if pred%a[i]!=0:
			flag=0
			break
	if(cnt!=n):
		flag = 0
	if(flag==1):
		print(pred)
	else:
		print(-1,cnt)
