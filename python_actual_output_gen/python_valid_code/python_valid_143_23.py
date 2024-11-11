n=int(input())
a=list(map(int,input().split()))

if n == 1:
    if a[0] == 0:
        print ('NO')
    else:
        print ('YES')
else:
    count = 0
    for i in range(n):
        if a[i] == 0:
            count += 1
    if count > 1:
        print ('NO')
    else:
        print ('YES')