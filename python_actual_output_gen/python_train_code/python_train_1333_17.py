n , k = map(int,input().split(' '))
arr = [int(i) for i in input().split(' ')]
arr.sort()
l , r = arr[n//2] , int(1e9)

while l < r :

    mid = (l+r+1)//2
    reqd = 0

    for i in range(n//2,n) :
        reqd+=max(mid - arr[i] , 0)
    
    if reqd > k :
        r = mid - 1
    else :
        l = mid

print(l)