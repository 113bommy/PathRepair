import sys
import math
  
instr = sys.stdin.readline().split("^")

ll = len(instr[0])
lr = len(instr[1]) - 1

res1 = 0
for i in range(ll - 1, -1, -1):
    if(instr[0][i] != '='):
        res1 += int(instr[0][i]) * (i - ll)

res2 = 0
for i in range(lr):
    if(instr[1][i] != '='):
        res2 += int(instr[1][i]) * (i + 1)

res = res1 + res2

if(res < 0):
    print("right")
elif(res > 0):
    print("left")
elif(res == 0):
    print("balance")