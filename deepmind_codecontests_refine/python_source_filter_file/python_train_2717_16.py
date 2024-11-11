from collections import *
n = int(input())
l = [*map(int,input().split())]
flag = False
flag1 = False
if(n == 1):
    print(l[0])
    exit()
for i in range(n):
    if(l[i] <= 0):
        flag = True
    if(l[i] >= 0):
        flag1 = True
if(flag and flag1):
    total = 0
    for i in range(n):
        total += abs(l[i])
    print(total)
elif(not flag and flag1):
    #print("ankush")
    print(sum(l) - 2 * min(l))
else:
    print(abs(sum(l)) + 2 * min(l))