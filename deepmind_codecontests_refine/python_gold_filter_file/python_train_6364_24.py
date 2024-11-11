n=int(input())
arr=list(map(int,input().split()))
#arr=list()
T=1
min_value=100*1000
for t in range(1,max(arr)+1):
	temp=0
	for i in arr:
		if i<t:
			temp+=abs(i-t+1)
		elif i>t:
			temp+=abs(t+1-i)
	if temp<min_value:
		min_value=temp
		T=t
print(T,min_value)
