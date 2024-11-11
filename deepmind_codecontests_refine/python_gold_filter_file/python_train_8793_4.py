n,m=map(int,input().split())
step=0
if n==m:
    print('0')
elif m<n:
    print(abs(m-n))
elif n<m:
    while m>n:
        if m%2==0:
            m=m/2
            step+=1
        else:
            m=m+1
            step+=1

    step+=abs(n-m)
    print(int(step))



