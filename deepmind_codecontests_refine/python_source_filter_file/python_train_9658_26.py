N=int(input())
a=tuple(map(int,input().split()))
c=0
for i in range(N):
	if i%2 and a[i]%2:c+=1
print(c)