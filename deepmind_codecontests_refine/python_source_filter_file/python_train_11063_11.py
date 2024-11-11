import sys
sys.setrecursionlimit(10**8)
try: 
	FILE_POINTER = open('input.inpt')
	input = FILE_POINTER.readline
except: 
	FILE_POINTER = None
	input = sys.stdin.readline

# ********************* Write your code from here ********************

t = int(input())
for _ in range(t):
	n = int(input())
	arr = list(map(int, input().strip().split()))
	
	k = 0
	for i in range(0,n,2):
		if (arr[i] == 0 and arr[i+1] == 1):
			arr[i+1] = -1
			k += 1
		elif (arr[i] == 1 and arr[i+1] == 0):
			arr[i] = -1
			k += 1
	print(k)
	for i in range(n):
		if arr[i] != -1:
			print(arr[i], end = " ")
	print()
	
# *********************      Code ends here       ********************	
	
if FILE_POINTER:
	FILE_POINTER.close()