def primefactorize(n):
    global Counter
    i=2
    while i<=n**(1/2):
        if n==1:
            break
        if n%i==0:
            n//=i
            if i in Counter:
                Counter[i]+=1
            else:
                Counter[i]=1
        else:
            i+=1
    if n!=1:
        if n in Counter:
            Counter[n]+=1
            
        else:
            Counter[n]=1



for i in range(int(input())):
    p,q=map(int,input().split())
    Counter= dict()
    primefactorize(q)
    ans=float('-inf')
    
    if p%q!=0:
        print(p)
        continue
    for i in Counter:
        x=p
        while x%q==0:
            x//=i
        if x>ans:
            ans=x
    print(ans)
        



