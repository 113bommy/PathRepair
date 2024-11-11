n=int(input())
fl=0
for _ in range(n):
    a,b,c=input().split()
    b=int(b)
    c=int(c)
    if(b<c):
        if(b>=2400 and c>2400):
            fl=1
            break
if(fl==1):
    print('YES')
else:
    print('NO')
    