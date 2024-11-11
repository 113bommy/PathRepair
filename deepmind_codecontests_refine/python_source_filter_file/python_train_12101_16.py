def binarySearch (mini,maxi,k) :
    if maxi - mini <= 1 :
        return maxi
    else :
        mid = (maxi + mini)//2
        total = (((mid+1)+2)*mid)//2
        if total > k :
            maxi = mid
        elif total == k :
            return mid
        else :
            mini = mid
        
        return binarySearch(mini,maxi,k)
        

def solve(n,k) :
    st = ['a']*n
    st[-1] = 'b'
    st[-2] = 'b'
    
    k -= 1
    if k == 0 :
        return "".join(st)
    
    firstBLoc = binarySearch(0,n-2,k-1)
    
    st[(n-2)-firstBLoc] = 'b'
    st[-2] = 'a'
    
    movesDone = ((firstBLoc+2)*(firstBLoc-1))//2
    leftover = k - movesDone - 1
    
    if leftover == 0 :
        return "".join(st)
        
    else :
        st[n-1-leftover] = 'b'
        st[n-1] = 'a'
        return "".join(st)
        


for x in range(int(input())):
    n,k = list(map(int,input().split()))
    print (solve(n,k))
    
    
    
    
        
         
    
    

