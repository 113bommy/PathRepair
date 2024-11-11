from sys import stdin, stdout
import math

n = int(stdin.readline())
arr = []

for i in range(n):
    temp_arr = [int(x) for x in stdin.readline().split()]
    arr.append(temp_arr)

x1 = (arr[0][n-1]/arr[1][n-1])
x2 = (arr[0][1]/arr[2][1])
y = (arr[1][2])*x1*x2
a0 = int(math.sqrt(y))
final_arr = []

for i in range(n):
    if i == 0:
        final_arr.append(a0)
    else:
        temp = arr[0][i]
        final_arr.append(int(temp/a0))

for num in final_arr:
    stdout.write(str(num) + ' ')



