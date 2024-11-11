arr = input().split(" ")
A = int(arr[0])
B = int(arr[1])
C = int(arr[2])
N = int(arr[3])

fail = N - (A+B-C)
if(C>B or C>A):
	print(-1)
if(fail<=0):
	print(-1)
else:
	print(fail)