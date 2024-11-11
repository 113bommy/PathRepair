def bin_search(arr, value):
    l,h = 0,len(arr)-1
    while l<=h:
        x = (h+l)//2
        if value < arr[x]:
            h = x-1
        elif value > arr[x]:
            l = x+1
        else:
            return x
    return h

n, k, A, B = map(int,input().split())
avg = list(map(int,input().split()))
avg.sort()

def min_power( l,h, a ):
    if len(a)==0: return A
    elif l==h: return B
    else:    
        mid = (l+h)//2
        #idx = bin_search(a, mid)
        left, right = [],[]
        for i in a:
            if i<=mid: left.append(i)
            else: right.append(i)
        
        pow_a = B*len(a)*(h-l+1)
        pow_b = min_power( l, mid, left) + min_power( mid+1, h, right )
        
        return min( pow_a, pow_b )
print(min_power( 1, pow(2,n), avg))