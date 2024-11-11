arr = []
for i in range(8):
    arr.append(input())
white = black = 0
for i in range(1,8):
    for j in range(8):
        if arr[i][j]=='W':
            check = 0
            for k in range(i):
                if arr[k][j]!='.':
                    check = 1
                    break
            if check==0:
                white = i
                break
    if white:
        break
for i in range(-2,-9,-1):
    for j in range(8):
        if arr[i][j]=='B':
            check = 0
            for k in range(-1,-i,-1):
                if arr[k][j]!='.':
                    check = 1
                    break
            if check == 0:
                black = 7-(8+i)
                break
    if black:
        break
if white==0 or black==0:
    if white==0:
        print('B')
    else:
        print('A')
elif white<=black:
    print('A')
else:
    print('B')
        