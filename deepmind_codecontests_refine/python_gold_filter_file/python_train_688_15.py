n=int(input())
arr=[1,2]
a=""
for i in range(2,n):
	arr.append(arr[abs(i)-1]+arr[abs(i)-2])
for i in range(1,n+1):
	if i in arr:
		a+="O"
	else:
		a+="o"
print(a)