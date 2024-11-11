n = int(input())
lis = []
for i in range(n):
    lis.append(list(map(int, input().split())))

flag = 0
init = max(lis[0])
for i in lis[1:]:
    temp_lis = sorted(i)
    if(temp_lis[0] > init):
        flag = 1
        break 
    elif temp_lis[1] <= init:
        init = temp_lis[1]
    else:
        init = temp_lis[0]

if(flag == 0):
    print ('YES')
else:
    print ('NO')
