from collections import deque
n,l=map(int,input().split())
a1=[0]*l
b1=[0]*l
a=map(int,input().split())
b=map(int,input().split())
if a==0 and b==0:
    print('NO')
    exit()
for i in a:
    a1[i]=1
for i in b:
    b1[i]=1
a=deque(a1)
b=deque(b1)
c=0
for i in range(l-1):
    a.rotate()
    if a==b:
        c=1
        break
print('YES') if c==1 else print('NO')