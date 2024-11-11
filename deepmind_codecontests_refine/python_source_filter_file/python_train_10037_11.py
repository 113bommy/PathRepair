s = input()
n = len(s)
arr = []
for i in range(n):
	arr.append(s[i])
for i in range(n-2):
	if arr[i]==arr[i+1]==arr[i+2]:
		arr[i]=""
arr1 = []
for i in arr:
	if i!="":
		arr1.append(i)
arr = arr1
n = len(arr)
for i in range(n-3):
	if arr[i]==arr[i+1] and arr[i+2]==arr[i+3]:
		arr[i]=""
for i in arr:
	print(i,end="")
print()