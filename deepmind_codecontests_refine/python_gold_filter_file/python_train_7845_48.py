n=int(input())
s=0
for i in range(n):
    a=int(input())
    s=round(abs(360/(a-180)))
    if a==((s-2)*180)/s:
        print('YES')
    else:
        print('NO')
