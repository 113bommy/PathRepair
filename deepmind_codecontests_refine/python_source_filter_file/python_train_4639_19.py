import sys
import math

a,b = map(int,input().split())
n = int(input())
time = 200
for i in range(n):
    arr = list(map(int,input().split()))
    x = arr[0]
    y = arr[1]
    v = arr[2]

    distance = math.sqrt((x-a)*(x-a)+(y-b)*(y-b))
    if distance*(1/v) < time:
        time = distance*(1/v)
print(time)