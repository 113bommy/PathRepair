x,y = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
i = 0
j = 1
count = 0
while(j<len(a)):
	if abs(a[i]-a[j])>=y:
		count+=1
		a[i]=-1;
		a[j]=-1;
	else:
		j+=1
	while(i<len(a) and a[i]==-1):
		i+=1
	while(j<len(a) and (a[j]==-1 or j<=i)):
		j+=1
print(count)