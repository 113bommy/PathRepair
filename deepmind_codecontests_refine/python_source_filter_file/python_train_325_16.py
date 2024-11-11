n,x,y = map(int,input().split())
num = input().strip()
num = num[n-x:]
count=0
for y in range(len(num)):
	if(num[y]=='1'):
		count+=1
if(num[x-y]=='1'):
	count-=1
else:
	count+=1
print(count)