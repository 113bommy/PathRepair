for t in range(int(input())):
    n,k=[int(k) for k in input().split()]
    a=[int(k) for k in input().split()]
    if n==1:
        print("Yes")
        continue
    sa=sorted(a)
    dic={}
    for i in range(n):
        dic[sa[i]]=i
    i=0
    k-=1
    while k and i<n-1:
        if dic[a[i+1]]!=dic[a[i]]+1:
            k-=1
        i+=1
    if k>=0 and i==n-1:
        print("Yes")
    else:
        print("No")
        
        
        
        
    