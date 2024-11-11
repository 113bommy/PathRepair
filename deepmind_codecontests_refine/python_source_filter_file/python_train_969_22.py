# 155A. I_love_%username%
n = int(input())
lst = [int(k) for k in input().split()]
mini = 10000
maxi = 0
s = 0
for i in range(n):
    if lst[i] > maxi:
        maxi = lst[i]
        s += 1
    if lst[i] < mini:
        mini = lst[i]
        s += 1
if s >= 2:
    print(s - 2)
else:
    print(0)
