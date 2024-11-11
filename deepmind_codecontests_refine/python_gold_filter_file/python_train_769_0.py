from collections import defaultdict
import sys
sys.setrecursionlimit(10**8)
try: 
	FILE_POINTER = open('input.inpt')
	input = FILE_POINTER.readline
except: 
	FILE_POINTER = None
	input = sys.stdin.readline

n = int(input())
arr = []
for _ in range(n):
	arr.append(int(input()))
arr.sort(reverse = True)

ans = 0
i = 0
j = n//2
hs = [1]*n
while j < n:
	while j <n and arr[j]>(arr[i]//2):
		j += 1
	if i <n and j<n:
		hs[i] = hs[j] = 0
		ans += 1
		i += 1
		j += 1
for i in range(n):
	if hs[i]:
		ans += 1
print(ans)
	

if FILE_POINTER:
	FILE_POINTER.close()