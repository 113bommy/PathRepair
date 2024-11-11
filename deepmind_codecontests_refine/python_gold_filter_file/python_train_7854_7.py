import sys
import random

n = int(sys.stdin.readline())
days = []
for i in range(n):
	in_days = sys.stdin.readline().split(" ")
	days.append((int(in_days[0]), int(in_days[1])))

def sorter(days_list):
	if len(days_list) < 2:
		return days_list
	pivot = days_list[random.randrange(len(days_list))]
	left = []
	right = []
	for index, elem in enumerate(days_list):
		if elem == pivot:
			continue
		if elem > pivot:
			right.append(elem)
		else:
			left.append(elem)
	return sorter(left) + [pivot]+sorter(right)

days = sorter(days)
for index, day in enumerate(days):
	if index == 0:
		if day[1] < day[0]:
			days[0] = (day[1], day[0])
		continue
	if day[1] >= days[index-1][0]:
		days[index] = (day[1], day[0])

print(days[-1][0])
