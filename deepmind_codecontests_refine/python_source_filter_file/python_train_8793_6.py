n,m=(list(map(int,input().split())))
count=0
if n>=m:
    print(n-m)
else:
    while(m>n):
        if m%2==0:
            m /= 2
            count += 1
        else:
            m +=1
            count += 1
    print(count+(n-m))
        