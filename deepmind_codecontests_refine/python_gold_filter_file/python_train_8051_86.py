n=int(input())
list1=list(map(int,input().split()))
sumy=0
for i in range(0,n,1):
	sumy+=list1[i]
print(sumy/n)