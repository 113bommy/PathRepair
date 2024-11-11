N=int(input())
a=tuple(map(int,input().split()))
c=0
for i in range(1,N+1):
	if i%2 and a[i-1]%2:c+=1
print(c)