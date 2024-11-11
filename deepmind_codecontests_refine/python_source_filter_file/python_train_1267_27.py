from collections import deque

n, x, y = map(int, input().split())
arr = list(map(int, input().split()))

left_dq = deque()
right_dq = deque()
for i in range(1, y):
	while right_dq and arr[right_dq[-1]] > arr[i]:
		right_dq.pop()
	right_dq.append(i)

ans = 1
if x==0 and y==0:
	ans = min(arr)

for i in range(n):
	while left_dq and left_dq[0] < i-x:
		left_dq.popleft()
	while right_dq and right_dq[0] <= i:
		right_dq.popleft()
	if i > 0:
		while left_dq and arr[left_dq[-1]] > arr[i-1]:
			left_dq.pop()
		left_dq.append(i-1)
		min_left = arr[left_dq[0]]
	else:
		min_left = float('inf')
	if i+y < n:
		while right_dq and arr[right_dq[-1]] > arr[i+y]:
			right_dq.pop()
		right_dq.append(i+y)
		min_right = arr[right_dq[0]]
	else:
		min_right = arr[right_dq[0]] if right_dq else float('inf')
	if arr[i] < min_left and arr[i] < min_right:
		ans = i+1
		break
print(ans)