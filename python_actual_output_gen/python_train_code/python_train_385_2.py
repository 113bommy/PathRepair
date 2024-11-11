h,n = [int(i) for i in input().split()]
total = 2**h
ans = 0
i = 0
l,r = 1,2**h
curr = 0
while(i<=h):
    mid = (l+r-1)//2
    if i==h-1:
        if curr==0:
            if l==n:
                ans+=1
            else:
                ans+=2
        else:
            if l==n:
                ans+=2
            else:
                ans+=1
        break
    if curr==0:
        if mid<n:
            ans += 2**(h-i)
            l = mid+1
        else:
            ans+=1
            r = mid
            curr=1
    else:
        if n<mid:
            ans+= 2**(h-i)
            r = mid
        else:
            ans+=1
            l = mid+1
            curr=0
    i+=1
print(ans)