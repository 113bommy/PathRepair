# -*- coding: utf-8 -*-


x =int(input())
arr = []

for i in range(0,x):
    cur = input()
    arr.append(cur)

sum = 0
for i in range(1,x-1):
    for j in range(1,x-1):
        if arr[i][j]=='X' and arr[i][j-1]=='X' and arr[i][j+1]=='X' and arr[i+1][j]=='X' and arr[i-1][j]=='X':
            sum+=1

print(sum)            