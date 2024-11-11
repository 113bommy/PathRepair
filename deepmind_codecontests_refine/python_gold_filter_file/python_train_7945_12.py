# import sys
# sys.stdin = open('input.txt', 'r') 
# sys.stdout = open('output.txt', 'w')

def solve(arr, n):
	count = 0
	for i in range(n):
		left, right, upper, lower = False, False, False, False
		for j in range(n):
			
			if i != j:
				if arr[i][0] == arr[j][0]:
					if arr[j][1] < arr[i][1]:
						upper = True
					else:
						lower = True

				if arr[i][1] == arr[j][1]:
					if arr[j][0] < arr[i][0]:
						left = True
					else:
						right = True

		if left and right and upper and lower:
			count += 1

	return count

n = int(input())

arr = []
for _ in range(n):
	arr.append(list(map(int, input().strip().split())))
# arr = list(map(int, input().strip().split()))
result = solve(arr, n)
print(result)