import sys
input = sys.stdin.readline
 
for _ in range(int(input())):
    l = int(input())
    a = list(map(int,input().split()))
    b = []
    for i in range(l):
        a[i] = a[i] % l
        b.append(0)
    for i in range(l):
        b[(a[i]+i)%l] = 1
    s = 1
    for c in b:
        if c != 1:
            s = 0
    if s == 1:
        print('yes')
    else:
        print('no')