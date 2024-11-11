# max(a[i] - a[i - 1] - c),i = 2..n
n,c=map(int,input().split())

a=list(map(int,input().split()))
t=[]
for i in range(0,max(n-2,1)):
	t.append(a[i]-a[i+1]-c)

else:

	print(max(0,max(t)))