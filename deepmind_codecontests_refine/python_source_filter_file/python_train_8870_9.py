import math

n,a,b,k = map(int,input().split())
lst		= list(map(int,input().split()))
dp      = [0 for i in range(n)]


total = a+b
for i in range(n):
	cur = lst[i]%total
	if(cur==0):
		cur = total

	dp[i] = math.ceil(cur/a)-1

print(*dp)
dp.sort()
print(*dp)

i = 0
k = k - dp[0]
count = 0

while(i<n-1 and k>=0):
	count+=1
	i+=1
	k = k -dp[i]

if(k>=0):
	count+=1

print(count)


