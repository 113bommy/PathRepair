# cook your dish here

t = int(input())

while t>0:
    
    maxVal = 0

    n = int(input())
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))

    lo = 0
    hi = n-1

    while lo <= hi and (arr2[lo]-arr1[lo]) == 0:
        
        lo += 1
        

    while lo < hi and (arr2[hi]-arr1[hi]) == 0:
        
        hi -= 1
        
    flag = False
    
    while lo < hi:
        
        diffLo = arr2[lo] - arr1[lo]
        diffHi = arr2[hi] - arr1[hi]

        if diffLo == diffHi and diffLo>=0 and diffHi>=0:
            lo += 1
        else:
            flag = True
            break
        
    if n == 1:
        if arr2[0] >= arr1[0]:
            print("YES")
        else:
            print("NO")
    elif flag:
        print("NO")
    else:
        print("YES")

    t -= 1