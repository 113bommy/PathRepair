n, k = [int(x) for x in input().split()]
if k*(k-1)<n:
    print('no')
else:
    print('yes')
    a, b = 1, 2
    for i in range(n):
        print(a,b)
        if a<b:
            a,b=b,a
        else:
            a,b=b,a
            if b<n:
                b+=1
                if b==a:
                    b+=1
            else:
                a+=1
                b=a+1
