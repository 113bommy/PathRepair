import sys
n = int(input())
arr = list(map(int,input().split()))
s = sum(arr)
m = int(input())
s2 = 0
l = r = 0
for i in range(m):
    l,r = map(int,input().split())
    if(s2 == 0):
        if(l <= s and s >= r):
            s2 = s
        elif(s < l ):
            s2 = l

if(s <= r):
    print(s2)
else:
    print('-1')