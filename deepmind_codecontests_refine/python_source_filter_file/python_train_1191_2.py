n = int(input())
a = list(input().split())
i = 0
while i<n :
    a[i] = int(a[i])
    i = i+1
b,i = True,1
while i<n :
    if a[i-1]>=a[i] :
        b = False
        break
    i = i+1
if b :
    print('yes')
    print('1 1')
else :
    i = 1
    while a[i-1]<a[i] :
        i = i+1
    p = i-2
    while i<n and a[i-1]>a[i] : 
        i = i+1
    q = i
    while i<n and a[i-1]<a[i] : 
        i = i+1
    if i!=n :
        print('no')
    else :
        if p==-1 and q==n :
            print('yes')
            print(1,n)
        elif p==-1 :
            if a[0]<a[q] :
                print('yes')
                print(1,q+1)
            else :
                print('no')
        elif q==n :
            if a[p]<a[n-1] :
                print('yes')
                print(p+1,n)
            else :
                print('no')
        else :
            if a[p+1]<a[q] and a[p]<a[q-1] :
                print('yes')
                print(p+2,q)
            else :
                print('no')
