for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    
    if(n!=k):
        l = sorted(list(a))
        d = {}
        for i in range(n):
            d[l[i]] = i
        
        b=0
        for i in range(n-1):
            if(d[a[i]]!=d[a[i+1]]-1):
                b+=1
        b+=1
    
        print("Yes" if(b<=k) else "No")
    else:
        print("Yes")
        