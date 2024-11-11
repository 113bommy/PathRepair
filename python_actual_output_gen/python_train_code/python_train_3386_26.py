# import sys
# sys.stdin = open('input.txt', 'r') 
# sys.stdout = open('output.txt', 'w')

def solve(arr, n, k):
	arr.sort()
	
	current = 1
	skipped = 0
	for i in range(n):
		# if arr[i][0] > current:
		skipped += (arr[i][0] - current) // k
		current = arr[i][1]
	return arr[n-1][1] - skipped*k

n, k = list(map(int, input().strip().split()))

arr = []
for _ in range(n):
	arr.append(list(map(int, input().strip().split())))

# arr = list(map(int, input().strip().split()))
result = solve(arr, n, k)
print(result)