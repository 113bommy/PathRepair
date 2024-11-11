n,m = list(map(int,input().split(':')))
k,p = list(map(int,input().split(':')))
a = n+60*m
b = k+60*p
if b > a :
    s = (b + a) // 2
else :
    s = (b + 24*60 + a) // 2

a = s//60
if a < 10:
    a = '0'+str(a)
else:
    a = str(a)

b = s % 60
if b < 10:
    b = '0'+str(b)
else:
    b = str(b)
print('{}:{}'.format(a,b))