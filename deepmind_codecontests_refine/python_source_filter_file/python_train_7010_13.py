n,m = map(int,input().split())
if n==0 and m>0:
    print("Impossible")
elif n==0 and m==0:
    print(0)
elif m==0:
    print(n,n)
else:
    x = n
    y = m
    count = 0
    while x>0 and y>0:
        x-=1
        y-=1
        count+=1
    if x>0:
        count+=x
    if y>0:
        count+=y
    mini = count
    count = 0
    count += (n+m-1)
    maxi = count
    print(mini,maxi)
