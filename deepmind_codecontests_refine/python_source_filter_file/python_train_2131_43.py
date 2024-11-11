import sys
import math

a = int(sys.stdin.readline())

for i in range(1, 11):
    y = a + i
    for j in str(y):
        if(j == '8'):
            print(i)
            exit()
        