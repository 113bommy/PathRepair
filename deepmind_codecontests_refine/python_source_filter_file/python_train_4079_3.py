'''Author- Akshit Monga'''
from sys import stdin, stdout
input = stdin.readline
t = int(input())
for _ in range(t):
    n=int(input())
    data=[]
    for i in range(n):
        data.append([int(x) for x in input().split()])
    y_low=-10**5
    y_high=10**5
    x_low=-10**5
    x_high=10**5
    vals=sorted(data,key=lambda x:x[1],reverse=True)
    ans=1
    for i in vals:
        if y_low<=i[1]<=y_high:
            if i[3]==0 and i[5]==0:
                y_low=y_high=i[1]
            elif i[3]==0:
                y_high=i[1]
            elif i[5]==0:
                y_low=i[1]
        else:
            if i[3] == 0 and i[5] == 0:
                ans=0
                break
            elif i[3] == 0:
                if i[1]<y_low:
                    ans=0
                    break
            elif i[5] == 0:
                if i[1] > y_high:
                    ans = 0
                    break
    if not ans:
        print(ans)
        continue
    vals = sorted(data, key=lambda x: x[0], reverse=True)
    ans = 1
    for i in vals:
        if x_low<=i[0]<=x_high:
            if i[2]==0 and i[4]==0:
                x_low=x_high=i[0]
            elif i[2] == 0:
                x_low=i[0]
            elif i[4]==0:
                x_high=i[1]
        else:
            if i[2] == 0 and i[4] == 0:
                ans = 0
                break
            elif i[2] == 0:
                if i[0] > x_high:
                    ans = 0
                    break
            elif i[4] == 0:
                if i[0] < x_low:
                    ans = 0
                    break
    if not ans:
        print(ans)
        continue
    print(1,x_low,y_low)