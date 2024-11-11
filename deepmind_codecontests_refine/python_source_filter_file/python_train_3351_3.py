a=int(input())
i=0
for i in range(a):
    s=set(str(input()))
    t=set(str(input()))
    if s==t:
        print('YES')
    else:
        print('NO')
    i+=i
