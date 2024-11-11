for w in range(int(input())):
    n,l=tuple(map(int,input().split()))
    a=list(map(int,input().split()))
    s1=0
    s2=l
    c=0
    ans=-1
    if(n==1):
        if(a[0]==l/2):
            print(a[0])
        else:
            print(abs(l-2*a[0])/3 + min(a[0],l-a[0]))
    else:
        l1=[0]*n 
        l2=[0]*n 
        for i in range(n):
            if(i==0):
                l1[i]=a[i]
            else:
                l1[i]=(a[i]-a[i-1])/(i+1)+l1[i-1]
        for i in reversed(range(n)):
            if(i==n-1):
                l2[i]=l-a[i]
            else:
                l2[i]=(a[i+1]-a[i])/(n-i)+l2[i+1]
        for i in range(n):
            if(l1[i]==l2[i]):
                c=1
                ans=l1[i]
                break
        if(c==1):
            pass
            print(ans)
        else:
            for i in range(n-1):
                if(l2[i]>l1[i] and l1[i+1]>l2[i+1]):
                    c=1
                    ans=l1[i]+((l2[i+1]-l1[i])*(n-i) + a[i+1]-a[i])/(n+2)
                    
                    break
            if(c==1):
                pass
                print(ans)
            else:
                if(l1[0]<l2[0]):
                    print((n*l2[1]+a[0])/(n+2))
                else:
                    print((l-a[-1]+(n+1)*l1[-1])/(n+2))
        #print(l1)
        #print(l2)