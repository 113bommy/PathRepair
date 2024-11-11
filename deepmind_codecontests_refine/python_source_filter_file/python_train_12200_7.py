import math
n = int(input())
arr = [ list(map(int, input().split())) for x in range(n) ]

a00 = math.sqrt((arr[0][1] * arr[1][2]) / arr[1][2]);

print(int(a00), end=" ");
for i in range(1, n):
         print(int(arr[i][0] // a00 ), end=" ");
