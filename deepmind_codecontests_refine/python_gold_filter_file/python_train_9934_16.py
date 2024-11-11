a=[int(i)for i in input().split(':')]
b=[int(i)for i in input().split(':')]
c=a[0]-b[0]
d=a[1]-b[1]
if d<0:d+=60;c-=1
if c<0:c+=24
if c<10:print('0',end='')
print(c,end='')
print(':',end='')
if d<10:print('0',end='')
print(d,end='')
