def days(d):
    times = d//n
    more = d%n
    nextX = x1+(times*dayWind[-1][0])
    nextY = y1+(times*dayWind[-1][1])
    if more != 0:
        nextX += dayWind[more-1][0]
        nextY +=dayWind[more-1][1]
    return ([d,abs(x2-nextX)+abs(y2-nextY)])
x1,y1= map(int,input().split())
x2,y2= map(int,input().split())
dayWind = []
n = int(input())
forcast = list(input())
xx1 = x1
yy1 = y1
for i in forcast:
    if i == 'L':
        xx1 -= 1
    elif i == 'R':
        xx1 += 1
    elif i == 'D':
        yy1 -= 1
    else:
        yy1 += 1
    dayWind.append([xx1-x1,yy1-y1])
left = 1
right = 10**15
ans = []
right_value = []
while(left!=right):
    day = (left+right)//2
    ans = days(day)
    if day>=ans[1]:
        right = day
        right_value = ans
    else:
        left = day+1
print(right_value[0] if len(right_value)>0 else -1)


