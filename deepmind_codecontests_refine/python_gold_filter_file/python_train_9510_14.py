import sys
import math

n = int(sys.stdin.readline())
ni = [int(x) for x in (sys.stdin.readline()).split()]

min = 1000000001
count = 1

res = 0
for i in range(n):
    if(ni[i] < min):
        count = 1
        min = ni[i]
        res = i
    elif(ni[i] == min):
        count += 1

if(count > 1):
    print("Still Rozdil")
else:
    print(res + 1)       
        
    
    