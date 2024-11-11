n=int(input())
m=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
if((1 in a) or (1 in b)):
	print(-1)
else:
	#print(m)
	temp = m*(b[0]/(b[0]-1))
	#print(temp)
	for i in range(n-1,0,-1):
		temp = temp*(a[i]/(a[i]-1))
		#print(temp)
		temp = temp*(b[i]/(b[i]-1))
		#print(temp)
	temp = temp*(a[0]/(a[0]-1))
	print(temp)