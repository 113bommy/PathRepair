n = int(input())
count = 0
arr = [100,50,20,5,1]
for i in arr:
	count+=(n//i)
	n-=(n//i)*i
print(count)	