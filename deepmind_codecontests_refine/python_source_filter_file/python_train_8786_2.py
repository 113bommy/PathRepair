# coding: utf-8
m = int(input())
c = [int(i) for i in input().split()]
x, y = [int(i) for i in input().split()]
ans = 0
cnt1 = 0
while c and cnt1<x:
    cnt1 += c.pop()
cnt2 = 0
while c and cnt2<x:
    cnt2 += c[0]
    ans += 1
    del(c[0])
while c and cnt1+c[-1]<=y:
    cnt1 += c.pop()
while c and cnt2+c[-1]<=y:
    cnt2 += c[0]
    ans += 1
    del(c[0])
if not c and cnt1>= x and cnt1<=y and cnt2>= x and cnt2<=y:
    print(ans)
else:
    print(0)
