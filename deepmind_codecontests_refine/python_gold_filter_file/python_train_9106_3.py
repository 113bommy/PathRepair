a=input()
b=int(input())
c=len(a)//b
if len(a)%b:print('NO')
else:
    for i in range(b):
        if a[i*c:i*c+c]!=a[i*c:i*c+c][::-1]:
            print('NO')
            exit()
    print('YES')
