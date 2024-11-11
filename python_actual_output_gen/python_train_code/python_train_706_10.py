# import sys
# sys.stdout = open('output.txt', 'wt')
# sys.stdin = open('input.txt', 'r')
n = int(input())
a = list(map(int, input().split()))
f, c = 1, 0
for i in range(1, n):
    if f:
        if a[i] < a[i-1]:
            f = 0
    else:
        if a[i] < a[i-1]:
            print(-1)
            f = -1
            break
        else:
            c += 1
# if n == 2:
#     print(1)
else:
    if f != -1:
        if f == 1:
            print(0)
        else:
            if a[-1] > a[0]:
                print(-1)
            else:
                print(c)