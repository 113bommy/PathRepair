import sys
import math

n = int(input())
debt = 100000
for i in range(1,n+1):
	debt = math.floor((debt*1.05)/1000)*1000
print(debt)