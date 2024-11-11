import math
n = int(input())
s = input()
l1 = list(map(int,input().split()))
min1 = math.inf
ind = 0
for i in range(len(s)-1):
    if s[i]=="R" and s[i+1]=="L":
        d = l1[i+1]-l1[i]
        if d<min1:
            min1 = d
            ind = i
if ind:
    print(min1//2)
else:
    print(-1)
    