import sys

cnt = 1
arr = []
n, k = map(int, sys.stdin.readline().strip().split())
while cnt <= n:
	st = str(cnt)
	arr.append(int(st + st[::-1]))
	# print(arr[cnt-1])
	cnt += 1

cnt = 1
while cnt < n:
	arr[cnt] = (arr[cnt]+arr[cnt-1])%k
	cnt += 1
sys.stdout.write(str(arr[n-1]))