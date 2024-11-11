st = input()
a = [int(i) for i in input().split()]
d = [int(i) for i in input().split()]
p = int(input())

def f(x):
    dop = 0
    if a[0] < b*x:
        dop += (b*x - a[0])*d[0]
    if a[1] < s*x:
        dop += (s*x - a[1])*d[1]
    if a[2] < c*x:
        dop += (c*x - a[2])*d[2]
    return dop
b,s = 0,0
c = 0

for i in range(len(st)):
    if st[i] == 'B':
        b+=1
    if st[i] == 'S':
        s+=1
    if st[i] == 'C':
        c+=1

l = -1
r = 10**12

while r - l >1:
    mid = (r+l)//2
    # print('f : ' ,f(mid))
    if f(mid) <= p:
        l = mid
        # print('l :' , l)
    else:
        r = mid
        # print('r :' , r)
print(l)