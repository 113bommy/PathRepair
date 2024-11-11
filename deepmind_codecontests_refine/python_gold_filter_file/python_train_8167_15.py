# import sys
# sys.stdin=open('input.txt', 'r')
# sys.stdout=open('output.txt', 'w')

n, t=[int(k) for k in input().split()]
a=[int(k) for k in input().split()]
if len(a)!=n: a.append(1)
x=1
while x<t:
    x+=a[x-1]
if x==t: print('YES')
else: print('NO')