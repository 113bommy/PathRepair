n = int(input())
R = lambda :list(map(int,input().split()))
a = R()
a.sort()
m = (a[n-1] - a[0])*(a[2*n-1] - a[n]) 

for i in range(1,n-1) :
	m = min(m ,(a[n-1+i]-a[i])*(a[2*n -1] - a[0]))

print(m)