# -*- coding: utf-8 -*-
"""
Created on Mon Feb 18 21:05:51 2019

@author: HP
"""

x1,y1 = map(int,input().split())
xx,yy = map(int,input().split())
n=int(input())
x=0
y=0
s=input()
for i in s:
    if i is 'R':
        x+=1
    elif i is 'L':
        x-=1
    elif i is 'U':
        y+=1
    else:
        y-=1
start = 0
end = 10**18
while start<end:
    mid = (start+end)//2
    div = mid//n
    rem = mid%n
    currx = div*x
    curry = div*y
    for i in range(rem):
        if s[i] is 'R':
            currx+=1
        elif s[i] is 'L':
            currx-=1
        elif s[i] is 'U':
            curry+=1
        else:
            curry-=1
    currx = currx + x1
    curry = curry + y1
    dis = abs(currx-xx)+abs(curry-yy)
    if dis<=mid:
        end = mid
    else:
        start = mid+1

if start>=10**18:
    print(-1)
else:
    print(start)