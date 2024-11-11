t=int(input())
for x in range(t):
    n=int(input())
    if(1<=n<=10):
        print("1")
        print(n)
    else:
        i=1
        a=[]
        while(n>0):
            rem=n%10**i
            if((rem==0 and (n/10**i)%10==0)or n<10**i):
                a.append(n)
                break
            else:
                n-=rem
                a.append(rem)
                i+=1
        c=a.count(0)
        for i in range(c):
            a.remove(0)
        print(len(a))
        print(*a)
