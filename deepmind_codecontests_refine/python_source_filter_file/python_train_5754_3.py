for _ in range(int(input())):
    n,k,z=map(int,input().split())
    a=list(map(int,input().split()))
    ans=0
    s=[0]
    for i in range(n):
        s.append(s[len(s)-1]+a[i])
    for i in range(1,k+1):
        m=s[i+1]
        if 2*z==k-i:
            m+=(a[i-1]+a[i])*z
            # print('check1',m)
        elif 2*z<k-i:
            m+=(a[i-1]+a[i])*z+s[min(n,k+1-2*z)]-s[min(n,i+1)]
            print(s[min(n,k+1-2*z)],s[min(n,i+1)])
            # print('check2',m)
        else:
            m+=(a[i-1]+a[i])*((k-i)//2)+a[i-1]*(k-i-2*((k-i)//2))
            # print('check3',m)
        ans=max(m,ans)
    print(ans)