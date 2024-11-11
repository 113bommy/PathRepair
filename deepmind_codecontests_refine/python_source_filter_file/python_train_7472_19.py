import sys
read = sys.stdin.read

n = int(input())
ss = read().split()

cnt_p = []
cnt_m = []
for i in range(n):
    left = 0
    right = 0
    for s in ss[i]:
        if(s == '('):
            left += 1
        elif(s == ')'):
            if(left > 0):
                left -= 1
            else:
                right += 1
    if(left-right > 0):
        cnt_p.append((right,left))
    else:
        cnt_m.append((right,left))


cnt_p = sorted(cnt_p, key=lambda x: (x[0]))
cnt_m = sorted(cnt_m, key=lambda x: (x[0]*-1))
cnt = cnt_p + cnt_m
num = 0
for right,left in cnt:
    num -= right
    if(num < 0):
        print('No')
        exit()
    num += left

if(num==0):
    print('Yes')
else:
    print('No')