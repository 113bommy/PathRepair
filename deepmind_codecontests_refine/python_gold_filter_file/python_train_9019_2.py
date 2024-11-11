import sys
import math            

n = int(input())

if(n == 0):
    print("WIN")
    exit()

k = [0] * 5

for i in range(n):
    a, b = [int(x) for x in (sys.stdin.readline()).split()]
    k[a - 1] += 1
    k[b - 1] += 1


for i in range(5):
    if(k[i] != 2):
        print("WIN")
        exit()

print("FAIL")