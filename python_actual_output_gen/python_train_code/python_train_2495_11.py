n = int(input())
day = list(map(int, input().split()))
curr = 0
i = 0; flag = 0
while curr < n:
    curr += day[i]
    if i < 6:
        i += 1
    elif i == 7 and curr>=n:
        print(7)
        flag = 1
    else:
        i = 0
        
if flag == 0:
    print(i)