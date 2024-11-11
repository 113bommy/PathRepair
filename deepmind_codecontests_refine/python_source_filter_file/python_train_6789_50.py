import math
t = int(input())
for i in range(t):
    flag = True
    a,b = map(int,input().split())
    res = len(str(b)) - 1
    for j in str(b):
        if j!=9:
            flag = False
            break
    if flag:
        res+=1
    print(res*a)