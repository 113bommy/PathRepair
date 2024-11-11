def binsearch1(a,n,i):
    ans = -1
    l = i
    h = len(a)-1
    while h>=l:
        m = l+ (h-l)//2
        if n<=a[m]:
            ans = m
            h = m-1
        else:
            l=m+1
    return ans





def binsearch2(a,n,i):
    ans = -1
    l = i
    h = len(a)-1
    while h>=l:
        m = l+ (h-l)//2
        if a[m]<=n:
            ans = m
            l = m+1
        else:
            h=m-1
    return ans
print(binsearch2([1,2,3,4,5],1,4))

t = int(input())
for i in range(t):
    n,l,r = list(map(int,input().strip().split()))
    a = list(map(int,input().strip().split()))
    a.sort()
    # print(a)
    count = 0
    for i in range(n-1):
        if a[i]>r:
            break
        n1=l-a[i]
        n2=r-a[i]
        c=binsearch2(a,n2,i+1)
        d=binsearch1(a,n1,i+1)
        
        if c>=0 and d>=0:
            count = count + (c-d+1)
        # print(n1,n2)
        # print(i+1)
        # print(binsearch2(a,n2,i+1),binsearch1(a,n1,i+1))
        # print(count)
    print(count)