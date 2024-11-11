n=int(input())
count=0
arr=[None]*n
for i in range(n):
	arr[i]=input()
	if arr[i]==None:
		continue
	elif arr[i]!=arr[i-1]:
		count+=1
print(count)
