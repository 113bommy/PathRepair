for _ in range(int(input())) :
    n , k = map(int , input().split())
    arr = list(map(int , input().split()))
    mx = 0
    left  = 0
    l= 0
    r= k -1

    while l <= len(arr) - k   :

        if l == 0 :
            i = 1
            peek = 0
            while i < k-1 :
                if arr[i-1] < arr[i] and arr[i] > arr[i+1] :
                    peek+=1
                i+=1
            mx = peek

        else :

            if arr[l] > arr[l-1] and arr[l] > arr[l+1] :
                peek-=1

            if arr[r-1] > arr[r] and arr[r-1] > arr[r-2] :
                peek+=1


            if peek > mx :
                mx = peek
                left = l
        l , r = l+1 , r+1


    if mx == 0 :
        print(1,1)
    else :
        print(mx+1,left+1)




