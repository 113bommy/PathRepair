import math
n,k = input().split()
n = int(n)
k = int(k)
l = [int(input()) for _ in range(n)]
mp = [0 for i in range(k+1)]
for e in l:
	mp[e]+=1
count = 0	
j = math.ceil(n/2)
for i in range(1,k+1):
	bac = int(mp[i]/2)
	mp[i] = mp[i]%2
	if(j>=k):
		count+=bac*2
		j=j-bac
	else:
		count += j*2
		break
if(j>0):		
	for i in range(1,k+1):
		if(mp[i]==1):
			count+=1
			j-=1
		if(j<=0):
			break				
print(count)
