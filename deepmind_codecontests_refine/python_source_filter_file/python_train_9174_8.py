import sys
import math


line = input()
n, m, k = [int(x) for x in line.split()]
line = input()
numbers = [int(x) for x in line.split()]
diffs = []
for i in range(0, len(numbers)-1):
    diffs.append(numbers[i+1]-numbers[i])

diffs = sorted(diffs)
if k == 1:
    print(sum(diffs))
else:
    print(sum(diffs[0:-k+1])+k)
