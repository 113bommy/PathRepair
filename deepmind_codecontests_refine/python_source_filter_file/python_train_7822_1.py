from collections import deque
n = int(input())
a = deque(map(int,input().split()))
c = []
z = []
if(len(a)==1):
    print('1')
    print('L')
    exit()
while(True):
    if(len(a)==0):
        break
    if(a[0]<=a[-1] and len(c)==0):
        c.append('L')
        z.append(a[0])
        a.popleft()
    elif(a[0]>=a[-1] and len(c)==0):
        c.append('R')
        z.append(a[-1])
        a.pop()
    elif(a[0]>z[-1] and a[0]<a[-1]):
        c.append('L')
        z.append(a[0])
        a.popleft()
    elif(a[-1]>z[-1] and a[-1]<a[0]):
        c.append('R')
        z.append(a[-1])
        a.pop()
    elif(a[0]>z[-1]):
        c.append('L')
        z.append(a[0])
        a.popleft()
    elif(a[-1]>z[-1]):
        c.append('R')
        z.append(a[-1])
        a.pop()
    else:
        break
print(len(c))
print(''.join(c))
