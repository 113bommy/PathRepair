'''input
5 100
80 100 100 40 60
'''
# problem solving is essentially pattern recognition
from sys import stdin, stdout
import math
import collections

# main starts
n, m = list(map(int, stdin.readline().split()))
arr = list(map(int, stdin.readline().split()))
aux = dict()
for i in range(1, 101):
	aux[i] = 0
cur_sum = 0

for i in range(len(arr)):
	count = 0
	if cur_sum + arr[i] <= m:
		count = 0
	else:
		temp = 0
		for k in range(100, 0, -1):
			temp += k * aux[k]
			if cur_sum - temp + arr[i] <= m:
				temp -= k * aux[k]
				start = 1
				end = aux[k]
				while True:
					if start >= end:
						if cur_sum - temp - ((start - 1) * i) + arr[i] <= m:
							start -= 1
							break
						break

					mid = (start + end) //2 
					if cur_sum - (mid * k) - temp + arr[i] <= m:
						end = mid - 1
					else:
						start  = mid + 1

				if cur_sum - (start * k) - temp + arr[i] <= m:
					count += start
					break
				else:
					count += start + 1
					break
			else:
				count += aux[k]

	cur_sum += arr[i]
	print(count, end = ' ')
	aux[arr[i]] += 1