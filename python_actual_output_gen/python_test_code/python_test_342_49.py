#coding=utf-8

n = int(input().strip())
i = 1
s = 1
while  s < n:
    i += 1
    s += ((1 + i) * i) // 2
if i == 1:
    print('1')
else:
    print(i - 1)