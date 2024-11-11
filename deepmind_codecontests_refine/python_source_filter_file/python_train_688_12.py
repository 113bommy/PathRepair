n=int(input())
arr=[0,1,1]
a="O"
for i in range(3,n):
	arr.append(arr[abs(i)-1]+arr[abs(i)-2])
for i in range(2,n+1):
	if i in arr:
		a+="O"
	else:
		a+="o"
print(a)