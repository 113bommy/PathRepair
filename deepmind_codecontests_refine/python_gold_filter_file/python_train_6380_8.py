def fun(i):
    if (i==1):
        return 1
    a = p
    while(a%q==0):
        a = a//i
    return a
    
t = int(input())
for _ in range(t):
    p,q = list(map(int,input().split()))
    if (p%q!=0):
        print(p)
        continue
    ans = 1
    for i in range(1,q):
        if (i*i>q):
            break
        if (q%i==0):
            ans = max(ans,fun(i))
            ans = max(ans,fun(q//i))
    print(int(ans))