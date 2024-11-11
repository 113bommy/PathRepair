import sys
import math            

n = int(input())
st1 = input()
st2 = input()

k = 0
res = 0
for i in range(2 * n):
    if(st1[i] == '1' and st2[i] == '1'):
        k += 1
    elif(st1[i] == '1'):
        res -= 1
    elif(st2[i] == '1'):
        res += 1

res1 = int(k / 2) + k % 2
res2 = k - res1

if(res < 0):
    b = math.fabs(res)
    res1 += int(b / 2) + res % 2
elif(res > 0):
    res -= (k % 2)
    res2 += int(res / 2) + res % 2

if(res1 > res2):
    print("First")
elif(res1 < res2):
    print("Second")
else:
    print("Draw")