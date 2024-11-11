from sys import stdin, stdout 

# string input
n = int(stdin.readline())
 
arr = [int(x) for x in stdin.readline().split()]

arr.sort()
x1 = arr[0]
x2 = arr[n-1]
y1 = arr[n]
y2 = arr[(2*n) - 1]

mini = (x2-x1)*(y2-y1)
for i in range(1, n-1):
	j = i + n - 1
	x1 = arr[i]
	x2 = arr[j]
	y1 = arr[0]
	y2 = arr[2*n -1]
	prod = (x2-x1)*(y2-y1)
	if (prod < mini):
		mini = prod

print(mini)
# print to stdout
#stdout.write(str(summation))