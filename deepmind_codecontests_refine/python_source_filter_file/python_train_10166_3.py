def f(n):
    i=2
    while i*i<=n:
        if n%i==0:
            return False
        i+=1
    return True
p,y=map(int,input().split())
if p>10000:
    i=y
    while not f(i):
        if i==p:
            print(-1)
            exit()
        i-=1
    print(i)
else:
    for i in range(y,p,-1):
        for j in range(2,p+1):
            if i%j==0:
                break
        else:
            print(i)
            break
    else:
        print(-1)
    
    
