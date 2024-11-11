__author__ = 'hamed1soleimani'

dat = input().split()
n = int(dat[0])
s = int(dat[1])

sugars = list()
for i in range(n):
    dat = input().split()
    sugars.append((int(dat[0]), int(dat[1])))

buy = False
sweet = 0
for d, c in sugars:
    if s * 100 >= d * 100 + c:
        buy = True
        sw = 100 - c
        if 100 > sw > sweet:
            sweet = sw
if buy:
    print(sweet)
else:
    print(-1)
