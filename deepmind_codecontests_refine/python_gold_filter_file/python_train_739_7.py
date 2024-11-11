n=int(input())
a=[]
c=False
for i in range(n):
    a.append(int(input()))
for i in range(2**n):
    string=(n-len(bin(i)[2:]))*'0'+bin(i)[2:]
    summ=0
    for i in range(n):
        if string[i]=='0':
            summ+=a[i]
        else:
            summ-=a[i]
    if summ%360==0:
        print('YES')
        c=True
        break
if not c:
    print('NO')