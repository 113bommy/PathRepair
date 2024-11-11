a,b,k=map(int, input().split())
a,b=b,a
# a:1, b:0 

if k==0:
    print('Yes')
    print('1'*a+'0'*b)
    print('1'*a+'0'*b)
    exit()

if a<=1 or b==0:
    print('No')
    exit()


if a+b-1<=k:
    print('No')
    exit()

zero=b-1
xl=[0]
yl=[1]
for i in range(k-1):
    if zero>0:
        xl.append(0)
        yl.append(0)
        zero-=1
    else:
        xl.append(1)
        yl.append(1)

xl.append(1)
yl.append(0)
for i in range(a+b-k-2):
    if zero>0:
        xl.append(0)
        yl.append(0)
        zero-=1
    else:
        xl.append(1)
        yl.append(1)

xl.append(1)
yl.append(1)

xl=[str(x) for x in xl]
yl=[str(y) for y in yl]

print('Yes')
print(''.join(xl[::-1]))
print(''.join(yl[::-1]))
