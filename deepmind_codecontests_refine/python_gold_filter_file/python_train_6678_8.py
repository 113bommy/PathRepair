n=int(input())
arr=list(map(int,input().split()))
freq=[0]*200001
point=0
for i in range(n):
	freq[arr[i]]+=1
	if freq[arr[i]]> freq[arr[point]]:
		point=i
print(n-freq[arr[point]])
val=arr[point]
for i in range(point-1,-1,-1):
	if arr[i]<val:
		print(1,i+1,i+2)
	elif arr[i]>val:
		print(2,i+1,i+2)

for i in range(point+1,n):
	if arr[i]<val:
		print(1,i+1,i)
	elif arr[i]>val:
		print(2,i+1,i)
