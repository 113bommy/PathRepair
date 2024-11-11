
        

t = int(input())

while t:

    n = int(input())
    l1 = list(map(int, input().split()))
    
    arr =[0 for j in range(0,n)]
    print (arr)

    for i in range(0,n):
        val=i+l1[i]
        m=val%n

        if arr[m]==1:
            print ("NO")
            break
        else:
            arr[m]=1
    else:
        print ("YES")


    t=t-1