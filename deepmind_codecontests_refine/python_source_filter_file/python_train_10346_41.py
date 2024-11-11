from sys import stdin, stdout
import math

n, k = [int(x) for x in stdin.readline().strip().split()]
joy = []
time = []
for line in stdin.readlines():
    line = line.strip().split()
    joy.append(int(line[0]))
    time.append(int(line[1]))

results = []
for i in range(n):
    if time[i] > k:
        result = joy[i] + time[i] -k
        results.append(result)
    else:
        results.append(joy[i])
value = max(results)
    
print(value)