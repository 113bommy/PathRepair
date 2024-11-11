x = int(input())
h,m = map(int, input().split())

cnt = 0
while not str(h).__contains__('7') and not str(m).__contains__('7'):
    if m-x<0:
        if h==0:
            h = 23
        else:
            h -= 1
        m = 60-x
    else:
        m -= x
    cnt += 1

print(cnt)