while(1):
    try:
        n,m=map(int,input().split())
        a = list(map(int,input().split()))
        a.sort()
        minimum=a[n-1]-a[0]
        for i in range(1,len(a)-n):
            if (a[i+(n-1)]-a[i])<minimum:
                minimum=a[i+(n-1)]-a[i]
        print(minimum)
    except EOFError:
        break
    
