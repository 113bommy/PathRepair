def countGreater(arr, n, k): 
    l = 0
    r = n - 1
  
    # Stores the index of the left most element 
    # from the array which is greater than k 
    leftGreater = n 
  
    # Finds number of elements greater than k 
    while (l <= r): 
        m = int(l + (r - l) / 2) 
  
        # If mid element is greater than 
        # k update leftGreater and r 
        if (arr[m] >= k): 
            leftGreater = m 
            r = m - 1
  
        # If mid element is less than 
        # or equal to k update l 
        else: 
            l = m + 1
  
    # Return the count of elements  
    # greater than k 
    return (n - leftGreater)
n,m=map(int,input().split())
l=list(map(int,input().split()))
l=l+l
pre1=[0]*(2*n+1)
t=1
pre2=[0]*(2*n+1)
for i in range(2*n):
    pre1[t]=pre1[t-1]+l[i%n]
    pre2[t]=pre2[t-1]+((l[i%n]*l[i%n]+l[i%n])//2)
    t+=1
print(pre1)
print(pre2)
tot=0
for i in range(n):
    ans=0
    c=2*n+1-countGreater(pre1,2*n+1,pre1[i+n+1]-m)
    #print(c)
    ans=pre2[i+n+1]-pre2[c]
    #print(ans)
    left=m-pre1[i+n+1]+pre1[c]
    r=l[c-1]-left
    ans+=(l[c-1]*l[c-1]+l[c-1])//2-(r*r+r)//2
    tot=max(tot,ans)
    #print(ans)
print(tot)
    
    
    