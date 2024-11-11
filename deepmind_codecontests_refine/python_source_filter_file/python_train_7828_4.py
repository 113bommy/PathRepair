
n=int(input())
arr=list(map(int,input().split()))
arr.sort()
z=[]
count=1
for i in range(n-1):
	if arr[i]==arr[i+1]:
		count+=1
	else:
		if count!=1:
			z.append(count)
		count=1
if count!=1:
	z.append(count)
print(z)
z.sort()
ans=0
for i in range(len(z)):
	ans+=z[i]//4
	z[i]=z[i]%4
	z[i]=z[i]//2
#print(z)
z=list(filter(lambda x:x==1,z))
#print(z)
ans+=len(z)//2
print(ans)