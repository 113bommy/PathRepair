nk = input().split(' ')
n,k = int(nk[0]),int(nk[1])
a = list(map(int,input().split(' ')))

a.sort()
start = (n-1)//2

prev=1
max_med=a[start]
for i in range(start+1,n):
	required = (a[i]-a[i-1])*prev

	if k-required >= 0:
		k-=required
		prev+=1
		max_med = a[i]
	else:
		possible=k//prev
		max_med=a[i-1]+possible
		k=0

if k!=0:
	max_med += k//(prev)


print(max_med)